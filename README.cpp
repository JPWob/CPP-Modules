/*
MULTIPLEXING
In programming, I/O multiplexing means allowing a single thread or program 
\to monitor and handle multiple network connections or files at the exact 
same time without getting stuck (blocking) on any single one.

WHY CODE NEEDS POLL()
In Unix/Linux systems, almost everything (network sockets, open files, pipes, hardware devices) 
is represented as a file descriptor (an integer ID assigned by the OS).

When a program wants to read data from a socket (e.g., a web server receiving requests from users), 
calling read() usually blocks—it puts your program to sleep until data actually arrives.

*/