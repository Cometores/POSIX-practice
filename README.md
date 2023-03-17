# Practice in C for POSIX standard from the Ruhr University Bochum. 
**Goals:**
- Improve programming skills for C
- Work with Linux **system calls**
- Learn how **processes** and **threads** work
- Learn to write **multithreaded applications** for Linux

**Special feature:** 
- Programs must conform to the **ANSI C11** standard and compile with the **GNU C** compiler. To do this, call **gcc** with the following parameters: <br>
*gcc -std=c11 -pedantic -D_XOPEN_SOURCE=700 Wall -Werror -o prog prog.c*



## Basics
Programs of basic complexity, without system calls.

### Sieve
Implementation of a simplified version of the **Sieve of Eratosthenes** (an algorithm for computing all prime numbers to a given maximum).

### Lists
Implementation of the **lilo** and **filo** singly-linked list.



## IO
Operating with Linux Standart **Streams**.

### iorep
Implementation of an **Input-Output Repeater**. When entering a line into the console and pressing the Enter key, the line is immediately brought back.

### wsort
 **Word Sorting** program reads a list of words from the standard input channel (*stdin*), sorts this list alphabetically and outputs the sorted list on the standard output channel (*stdout*).