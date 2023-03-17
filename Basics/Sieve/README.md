# sieve
<p>Implementation of a simplified version of the <strong>Sieve of Eratosthenes</strong> (an algorithm for computing all prime numbers to a given maximum).</p> 
<p>The implementation  includes the following steps:</p>
<ol>
  <li><strong>Initialization of the required data structures:</strong> Use an array prime of the data type bool, in which it is noted whether the number i at index i of the array is prime or not prime. For example, <em>prime[42]</em> indicates whether the number 42 is prime. </li>
  <li><strong>Execution of the Sieve of Eratosthenes:</strong> The core idea of Eratosthenes' sieve is to successively strike non-prime numbers from an array of n entries by running through the array in ascending order, starting at 2, and striking all multiples of prime, i.e., non-prime, numbers. <em>The numbers 0 and 1 are special case and not prime - therefore 0 and 1 are stricken:</em></li>
  <li><strong>Numbers output</strong></li>
</ol>

## Task Notes:
- Program must conform to the **ANSI C11** standard and compile with the **GNU C** compiler. To do this, call **gcc** with the following parameters: <br>
*gcc -std=c11 -pedantic -D_XOPEN_SOURCE=700 Wall -Werror -o sieve sieve.c*
- Output functions, such as printf, do not need to be error handled in this task.
- Use a constant variable (***const int MAX = 100;***) that indicates the largest number considered. 