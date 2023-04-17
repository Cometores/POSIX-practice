# sieve
<p>Implementation of a simplified version of the <strong>Sieve of Eratosthenes</strong> (an algorithm for computing all prime numbers to a given maximum).</p> 
<p>The implementation  includes the following steps:</p>
<ol>
  <li><strong>Initialization of the required data structures:</strong> Use an array prime of the data type bool, in which it is noted whether the number i at index i of the array is prime or not prime. For example, <em>prime[42]</em> indicates whether the number 42 is prime. </li>
  <li><strong>Execution of the Sieve of Eratosthenes:</strong> The core idea of Eratosthenes' sieve is to successively strike non-prime numbers from an array of n entries by running through the array in ascending order, starting at 2, and striking all multiples of prime, i.e., non-prime, numbers. <em>The numbers 0 and 1 are special case and not prime - therefore 0 and 1 are stricken:</em></li>
  <li><strong>Numbers output</strong></li>
</ol>

**Task Notes:**
- Program must conform to the **ANSI C11** standard and compile with the **GNU C** compiler. To do this, call **gcc** with the following parameters: <br>
*gcc -std=c11 -pedantic -D_XOPEN_SOURCE=700 Wall -Werror -o sieve sieve.c*
- Output functions, such as printf, do not need to be error handled in this task.
- Use a constant variable (***const int MAX = 100;***) that indicates the largest number considered. 


# lilo
Implementation of the **Last In Last Out** list, which operates positive numbers and provides the following functions:
- ***int insertElement(int value)***: Adds a value to the list if it does not already exist. If successful, the function returns the inserted value, otherwise the value -1.
- ***int removeElement(void)***: Takes the oldest value from the list and returns it. If there is no value in the list, -1 is returned.


# filo
Implementation of the **First In Last Out** list, which operates positive numbers and provides the following functions:
- ***int insertElement(int value)***: Adds a value to the list if it does not already exist. If successful, the function returns the inserted value, otherwise the value -1.
- ***int removeElement(void)***: Takes the last inserted value from the list and returns it. If no value is present in the list, -1 is returned.

**Task Notes:**
- Helpful manual pages: **malloc(3)**, **free(3)**
- **Do not implement any list functionality in the main() function.** All operations necessary for list management must be performed in insertElement() and removeElement. However, you can extend the main() function to test your implementation.
- The header of the list is to be created as a global variable.
- The attempt to add a negative number to the list should be prevented and considered as an error.
- If an error occurs during the execution of a used function (e.g. *malloc(3)*), no error messages are to be output - but the error must be handled sensibly according to the task.


# isort
**Integer Sort** program which sorts an array of random numbers.
- Using the **qsort(3)** function to sort an array.
- Implementing the number comparison function.