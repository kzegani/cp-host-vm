#!/bin/bash

#update the software
apt-get update > /dev/null

#install g++
apt-get install -y g++ > /dev/null

#compile the source code
g++ textTransfer.cpp -o textReceiver

#create output file
touch output

#Grant execution permissions to the compiled binary
chmod +x textReceiver

./textReceiver
