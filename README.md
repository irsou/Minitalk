# Minitalk

## 🚀 Purpose
This projecct is focused on interprocess communication (IPC) using UNIX signals. The goal is to implement a simple client-server architecture where the client sends a message to the serve using SIGUSR1 and SIGUSR2 signals.

## Aditional details
- Each character in the message is encoded into binary and sent bit by bit. When receiving 8 signals, the server reconstructs the character and prints the message to the console.
- SIGUSR1 represents a binary 0 and SIGUSR2 represents a binary 1.



## ⚙️ How to compile
- The repository provides a makefile, so by using 'make' command two executables (server and client) are generated.
- To start the server run './server', the PID value will be printed.
- To run the client two arguments are required: './client pid_value "messsage"'

 
## 🌐 Related links

[Linux signal - man7.org](https://man7.org/linux/man-pages/man7/signal.7.html)

[Bitwise operators - GeeksforGeeks](https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/)

[Signal Handling - GNU libc](https://ftp.gnu.org/old-gnu/Manuals/glibc-2.2.3/html_node/libc_455.html#SEC465)

##  🤝Contributions
Contributions are welcome! Open an issue or submit a pull request to suggest improvements or fixes.
