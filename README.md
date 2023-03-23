# Practice in C for POSIX standard from the Ruhr University Bochum. 
**Goals:**
- Work with Linux **system calls**
- Learn how **processes** and **threads** work
- Learn to write **multithreaded applications** for Linux
- Improve programming skills for C

**Special feature:** 
- Programs must conform to the **ANSI C11** standard and compile with the **GNU C** compiler. To do this, call **gcc** with the following parameters: <br>
*gcc -std=c11 -pedantic -D_XOPEN_SOURCE=700 Wall -Werror -o prog prog.c*



## Basics
Programs of basic complexity, without system calls.

### sieve
Implementation of a simplified version of the **Sieve of Eratosthenes** (an algorithm for computing all prime numbers to a given maximum).

### lists
Implementation of the **lilo** and **filo** singly-linked list.



## IO
Operating with Linux Standart **Streams**.

### iorep
Implementation of an **Input-Output Repeater**. When entering a line into the console and pressing the Enter key, the line is immediately brought back.

### wsort
 **Word Sorting** program reads a list of words from the standard input channel (*stdin*), sorts this list alphabetically and outputs the sorted list on the standard output channel (*stdout*).


## File System
Working with files and folders using the inode table.

### alsym
**All Symbolic links** program that displays the names of all symbolic links files in the current directory.



## Processes
Working with processes with **fork(2)** and **exec(3)**.

### excufoe
**Execute For Each** program, which executes a command with each of the passed parameters once.

### party
**PARallel Task Player** program, which executes commands sent *through the command line* in parallel.

### hupsi
**Highly Unreliable Parallel Software Igniter**, program, which reads commands line by line *from standard input* and executes them in parallel.