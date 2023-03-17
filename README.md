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
Implementation of a simplified version of the <strong>Sieve of Eratosthenes</strong> (an algorithm for computing all prime numbers to a given maximum).

### Lists
Implementation of the **lilo** and **filo** singly-linked list.
