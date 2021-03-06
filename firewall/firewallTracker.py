import datetime
import sys
import select
from multiprocessing import Pipe
import socket
import fcntl
import os
from datetime import datetime
import struct
from collections import defaultdict

# Sample for test:
# cat sampledata.txt | python3 firewallTracker.py 1

# Run on firewall host
# sudo conntrack -E conntrack -o timestamp | python3 firewallTracker.py 1

events_dict = defaultdict(lambda: 0)
flow_state_dict = defaultdict(lambda: 0)

def main():

    poller = select.poll()

    logFile = open('log_firewall_events.txt', 'w')
    # Create a TCP/IP socket for events besides flow tracker.
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setblocking(0)

    # Bind the socket to the port
    server_address = ('localhost', 10000)
    print('starting up on %s port %s' % server_address)
    server.bind(server_address)

    # Listen for incoming connections
    server.listen(5)

    # Create a TCP/IP socket to send data to local
    localSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    localSocket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

    # Bind the socket to the port
    local_address = ('localhost', 10001)
    print('starting up on %s port %s' % local_address)
    localSocket.bind(local_address)

    # Listen for incoming connections
    localSocket.listen(1)

    # Wait for local verifier to connect. Comment next two lines when testing with sample data
    local_connection, local_client_address = localSocket.accept()
    print('new local verifier connection from', local_client_address)

    # Create stdin pipe
    pipeIn = sys.stdin

    # Commonly used flag setes
    READ_ONLY = select.POLLIN
    READ_WRITE = READ_ONLY | select.POLLOUT

    # Create output pipe
    pipe_recv, pipe_send = Pipe(duplex=False)

    #
    fd_to_object = {
        pipeIn.fileno(): pipeIn,
        server.fileno(): server,
        pipe_recv.fileno(): pipe_recv,
        pipe_send.fileno(): pipe_send
    }

    # Make input stream non-blocking
    old_flags = fcntl.fcntl(pipeIn.fileno(), fcntl.F_GETFL)
    fcntl.fcntl(pipeIn.fileno(), fcntl.F_SETFL, old_flags | os.O_NONBLOCK)

    poller.register(pipeIn)
    poller.register(server, READ_ONLY)
    poller.register(pipe_recv, READ_ONLY)
    poller.register(pipe_send, READ_ONLY)
    count  = 0

    while True:
        # print("waiting on poll")
        events = poller.poll()
        # print("poll output", events)

        for fd, flag in events:
            # print("fd:", fd, " flag:", flag )
            
                
            currentObject = fd_to_object[fd]

            if currentObject is pipeIn and (flag != select.POLLHUP):
                allOut = currentObject.read()
                for line in allOut.splitlines():
                    # print("received line: ", line)
                    logFile.write(str(datetime.now().strftime("%H:%M:%S.%f")) + ',' + str(count) + '\n')
                    count += 1
                    pipe_send.send(line)
            elif currentObject is pipeIn and (flag == select.POLLHUP) and len(events) == 1:

                local_connection.close()
                for key,item in fd_to_object.items():
                    poller.unregister(item)
                    if isinstance(item, socket.socket):
                        item.close()
                print("input closed. terminating")
                sys.exit()
                    

            elif currentObject is pipe_recv:
                data = currentObject.recv()
                # print("data:", data)
                for line in data.splitlines():
                    # print("data received: ", line)
                    if "block" in line:
                        # print("Sending to local: ", line )
                        local_connection.send(line.encode())
                    else:
                        tempOut = parse_line(line)
                        # print("Sending to local: ", tempOut)
                        # print([int(x) for x in tempOut])
                        # print("Number of bytes: ", len(tempOut))

                        local_connection.send(tempOut)

            elif flag & (select.POLLIN | select.POLLPRI):

                if currentObject is server:
                    # A "readable" server socket is ready to accept a connection
                    connection, client_address = currentObject.accept()
                    print('new connection from', client_address)
                    connection.setblocking(0)
                    fd_to_object[ connection.fileno() ] = connection
                    poller.register(connection, READ_ONLY)
                    print("connection from block adder")
                else:
                    data = currentObject.recv(1024)
                    if data:
                        # A readable client socket has data
                        print('received "%s" from %s' % (data, currentObject.getpeername()))
                        pipe_send.send(data)

                    else:
                        # Interpret empty result as closed connection
                        print('closing', currentObject.getpeername(), 'after reading no data')
                        # Stop listening for input on the connection
                        poller.unregister(currentObject)
                        currentObject.close()
            elif isinstance(currentObject, socket.socket) and flag & select.POLLHUP:
                # Client hung up
                print('closing', currentObject.getpeername(), 'after receiving HUP')
                # Stop listening for input on the connection
                poller.unregister(currentObject)
                currentObject.close()

            elif isinstance(currentObject, socket.socket) and flag & select.POLLERR:
                print('handling exceptional condition for', currentObject.getpeername())
                # Stop listening for input on the connection
                poller.unregister(currentObject)
                currentObject.close()

            elif currentObject is pipe_send:
                print("Error in pipe_send")
                sys.exit(1)
            else:
                print("Unknown context")
                sys.exit(2)

def parse_line(line):
    # print(line)
    flowList = []
    current_entry = line.split()
    flow = dict()
    index = 0

    flow['time'] = float(current_entry[index][1:-1])
    index += 1
    flowList.append(flow['time'])

    flow['event_type'] = current_entry[index][1:-1]
    index += 1
    flowList.append(flow['event_type'])

    flow['proto'] = current_entry[index]
    index += 1
    flowList.append(flow['proto'])

    flow['transport_protocol'] = int(current_entry[index])
    index += 1
    flowList.append(flow['transport_protocol'])

    if not flow['event_type'] == 'DESTROY':
        flow['flow_id'] = int(current_entry[index])
        index += 1
        flowList.append(flow['flow_id'])

        if (flow['proto'] == 'tcp') and ('src' not in current_entry[index]):
            flow['flow_state'] = current_entry[index]
            index += 1
            flowList.append(flow['flow_state'])
        else:
            flow['flow_state'] = "UNKNOWN"
            flowList.append('')
    else:
        flow['flow_state'] = "UNKNOWN"
        flowList.append(0)
        flowList.append('UNKNOWN')

    flow['srcIp'] = current_entry[index].split('=')[1]
    index += 1
    flowList.append(flow['srcIp'])

    flow['dstIp'] = current_entry[index].split('=')[1]
    index += 1
    flowList.append(flow['dstIp'])

    if 'sport' in current_entry[index]:
        flow['srcL4Port'] = int(current_entry[index].split('=')[1])
        index +=1
        flowList.append(flow['srcL4Port'])
    else:
        flow['srcL4Port'] = 0
        flowList.append(0)

    if 'dport' in current_entry[index]:    
        flow['dstL4Port'] = int(current_entry[index].split('=')[1])
        index +=1
        flowList.append(flow['dstL4Port'])
    else:
        flow['dstL4Port'] = 0
        flowList.append(0)

    flow['location'] = int(sys.argv[1])

    flowList.append(flow['location'])

    flowByteForm = [struct.pack("d", flow['time'])]
    flowByteForm.append(struct.pack("B", events_dict[flow['event_type']]))
    flowByteForm.append(struct.pack("B", flow['transport_protocol']))
    flowByteForm.append(struct.pack("B", flow_state_dict[flow['flow_state']]))
    flowByteForm.append(socket.inet_aton(flow['srcIp']))
    flowByteForm.append(socket.inet_aton(flow['dstIp']))
    flowByteForm.append(struct.pack("H", flow['srcL4Port']))
    flowByteForm.append(struct.pack("H", flow['dstL4Port']))
    flowByteForm.append(struct.pack("B", flow['location']))
    
    return b''.join(flowByteForm)
    
def createDict():
    events_dict["NEW"] = 1
    events_dict["UPDATE"] = 2
    events_dict["DESTROY"] = 3
    events_dict["BLOCK"] = 4
    events_dict["ALLOW"] = 5

    flow_state_dict["SYN_SENT"] = 11
    flow_state_dict["SYN_RECV"] = 12
    flow_state_dict["ESTABLISHED"] = 13
    flow_state_dict["FIN_WAIT"] = 14
    flow_state_dict["CLOSE_WAIT"] = 15
    flow_state_dict["LAST_ACK"] = 16
    flow_state_dict["TIME_WAIT"] = 17
    flow_state_dict["CLOSED"] = 18
    flow_state_dict["LISTEN"] = 19


if __name__ == '__main__':
    createDict()
    main()