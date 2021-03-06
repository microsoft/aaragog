#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Usage: ./runFirewall.sh <node>"
    exit 1
fi

sudo conntrack -F
sudo kill $(sudo lsof -t -i:10001)
sudo kill $(sudo lsof -t -i:10000)

echo $1

cd $HOME/aragog/firewall

sudo conntrack -E conntrack -o timestamp | python3 firewallTracker.py $1 &

sleep 5

cd $HOME/aragog/C++Verifier
./build/main.out --filesOrKafka kafka --KafkaAddress 10.10.1.10:9092 --numberOfChannels 4 --inputType socket &

cd $HOME/aragog/firewall

python3 measureCpuMem.py $1 &

echo "global started"

sleep 600
pkill -P $$

echo "global ended, terminating programs"
