# Practice in C for POSIX standard from the Ruhr University Bochum. 

A collection of problems in C programming with their solutions. The repository is based on the **"Operating Systems 2022"** course from **Ruhr-University Bochum**. The problems are aimed at an in-depth understanding of interaction with the POSIX operating systems kernel. The problems are divided into sections and go from the easy to the hard level.

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

### isort
**Integer Sort** program which sorts an array of random numbers.



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

### listrun
Program which executes a command once with each of the passed parameters **as a list**.

### excufoe
**Execute For Each** program, which executes a command with each of the passed parameters **as a string** once. The program is identical to **listrun** except that the program and parameters are passed as a string.

### party
**PARallel Task Player** program, which executes commands sent *through the command line* in parallel.

### hupsi
**Highly Unreliable Parallel Software Igniter**, program, which reads commands line by line *from standard input* and executes them in parallel.

### clash
**C language apprentice’s shell** that runs programs passed through stdin. Supports program execution in foreground and background modes, as well as changing the working directory.



## Threads
Working with **pthreads**.

### palim
**Parallel Line Matcher** program that prints the number of lines containing a given string in regular files.