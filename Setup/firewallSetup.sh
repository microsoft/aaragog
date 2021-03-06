#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Illegal number of parameters"
    exit 1
fi


if [ $1 -gt 8 ] || [ $1 -lt 5 ]; then
    echo "Value should be between 5 and 8 (inclusive)"
    exit 1
fi

# Get interface for port internet traffic
INT=$(ifconfig | grep -B1 128.* | grep -o "^\w*")
# Get interface for port communicating locally
LOCAL=$(ifconfig | grep -B1 10.10 | grep -o "^\w*")

# Update Local IP
sudo ifconfig $LOCAL 10.10.1.$1

# softwares required for local verifier and measurements.
sudo apt update
sudo apt install -y socat
sudo apt install -y python3-pip
pip3 install psutil

# Automate setup without prompt
echo iptables-persistent iptables-persistent/autosave_v4 boolean true | sudo debconf-set-selections
echo iptables-persistent iptables-persistent/autosave_v6 boolean true | sudo debconf-set-selections

sudo apt install -y iptables-persistent
sudo apt install -y conntrack conntrackd keepalived

# Get the repository
git clone --recurse-submodules https://github.com/microsoft/aragog.git

# Get the conntrackd primary-backup setup file
sudo cp /usr/share/doc/conntrackd/examples/sync/primary-backup.sh /etc/conntrackd/

# Setup and Compile the local verifier
cd $HOME/aragog/C++Verifier/
chmod u+x setup.sh
./setup.sh
make

# Get the conntrackd configuration file
sudo cp $HOME/aragog/firewall/conntrackd.conf /etc/conntrackd/

# Get the keepalived configuration file
sudo cp $HOME/aragog/firewall/keepalived.conf /etc/keepalived/

# Get the firewall rules file
sudo cp $HOME/aragog/firewall/rules.v4 /etc/iptables/


# Automatically replace the internface name in rules and configuration files
sudo sed -i -e "s/enp1s0/$INT/g" /etc/iptables/rules.v4

sudo sed -i -e s/enp1s0d1/$LOCAL/g /etc/conntrackd/conntrackd.conf

sudo sed -i -e s/enp1s0d1/$LOCAL/g /etc/keepalived/keepalived.conf

if [ $1 -gt 4 ] && [ $1 -lt 7 ]; then
    sudo sed -i -e s/10.10.X.100/10.10.4.100/g /etc/keepalived/keepalived.conf
    sudo sed -i -e s/10.10.1.Y/10.10.1.100/g /etc/keepalived/keepalived.conf
    sudo sed -i -e s/virtual_router_id\ A/virtual_router_id\ 61/g /etc/keepalived/keepalived.conf
    sudo sed -i -e s/virtual_router_id\ B/virtual_router_id\ 62/g /etc/keepalived/keepalived.conf
elif [ $1 -gt 6 ] && [ $1 -lt 9 ]; then
    sudo sed -i -e s/10.10.X.100/10.10.5.100/g /etc/keepalived/keepalived.conf
    sudo sed -i -e s/10.10.1.Y/10.10.1.50/g /etc/keepalived/keepalived.conf
    sudo sed -i -e s/virtual_router_id\ A/virtual_router_id\ 71/g /etc/keepalived/keepalived.conf
    sudo sed -i -e s/virtual_router_id\ B/virtual_router_id\ 72/g /etc/keepalived/keepalived.conf
fi

if [ $1 -eq 5 ]; then
    sudo sed -i -e s/10.10.1.Y/10.10.1.5/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/10.10.1.Z/10.10.1.6/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/priority\ P/priority\ 100/g /etc/keepalived/keepalived.conf
elif [ $1 -eq 6 ]; then
    sudo sed -i -e s/10.10.1.Y/10.10.1.6/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/10.10.1.Z/10.10.1.5/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/priority\ P/priority\ 50/g /etc/keepalived/keepalived.conf
elif [ $1 -eq 7 ]; then
    sudo sed -i -e s/10.10.1.Y/10.10.1.7/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/10.10.1.Z/10.10.1.8/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/priority\ P/priority\ 100/g /etc/keepalived/keepalived.conf
elif [ $1 -eq 8 ]; then
    sudo sed -i -e s/10.10.1.Y/10.10.1.8/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/10.10.1.Z/10.10.1.7/g /etc/conntrackd/conntrackd.conf
    sudo sed -i -e s/priority\ P/priority\ 50/g /etc/keepalived/keepalived.conf
fi

# Install rules
sudo iptables-restore < /etc/iptables/rules.v4
cd /etc/keepalived
nohup sudo keepalived -l &
cd /etc/conntrackd
nohup sudo conntrackd -d &

cd 
cd aragog/runme
chmod u+x runFirewall.sh

wait
