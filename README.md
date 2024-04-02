# VM Text Receiver Script

This script is designed to run on a virtual machine (VM) and listen for incoming connections on a specified port. When a connection is established, it will receive and print the text sent from another machine. This functionality can be particularly useful for transferring text or commands from a host machine to a VM, somewhat akin to a command-line version of the copy-paste functionality.

# Prerequisites

- A Linux-based VM set up and accessible.
- g++ installed on the VM for compiling the source code.
- The VM's firewall configured to allow incoming connections on the port used by the script (default port 13423).

# Installation

1. Ensure that g++ is installed on your VM. If not, you can install it by running:

```bash
sudo apt-get update && sudo apt-get install g++ -y
```

2. Copy the script file textTransfer.cpp to your VM.

3. Compile the source code using g++:

```bash
g++ textTransfer.cpp -o textReceiver
```

4. Grant execution permissions to the compiled binary:

```bash
chmod +x textReceiver
```

# Usage

Run the script on your VM to start listening for incoming connections:

```bash
./textReceiver
```

The script will listen on port 13423 by default. Ensure that this port is open in your VM's firewall settings.

From the host machine or another machine, you can send text to your VM using a tool like nc (netcat). For example:

```bash
echo "Hello, VM!" | nc <VM_IP_ADDRESS> 13423
```

Replace <VM_IP_ADDRESS> with the actual IP address of your VM.

When the script running on the VM receives a connection, it will print the text sent from the other machine to the console.

# Customizing Port Number

The default port used by the script is 13423. If you wish to use a different port, you will need to modify the script and change the value of the `Port` variable to your desired port number. Remember to recompile the script after making any changes.

# Security Note

This script is designed for copping text from host machine to virtual machine. Running a script that opens a port and prints received text can pose security risks. Ensure that your VM is appropriately secured and that you understand the implications of opening network ports on your machines.