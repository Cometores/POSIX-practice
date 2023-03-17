# iorep
Implementation of an **Input-Output Repeater** that operates with Linux Standard **Streams**. When entering a line into the console and pressing the Enter key, the line is immediately brought back.<br>
**Goals:**
- Using **stdin**, **stdout**, **stderr** streams.
- Competent **handling of errors**.
- Work with **errno**.

# wsort
**Word Sorting**. Program reads a list of words from the standard input channel (*stdin*), sorts this list alphabetically and outputs the sorted list on the standard output channel (*stdout*).

Both when reading in and outputting the words, each word is in its own line. A word includes **all** characters of a line. Lines are separated by a newline character (*\n*), which is not itself part of the word. Each line ends with a carriage return. Only the last line does not necessarily have to contain a *'\n'* character.

Words that exceed a maximum length of 100 characters are **ignored** with an appropriate error message. Empty lines are to be ignored without error message.

The files for testing the solution are in the files folder. The solution can be checked against the example solution **wsort.bsteam**, and the result of the program execution can be compared as follows: <br>

>**\$** ./wsort < ./files/wlist0 > wlist0.mine <br>
**\$** ./wsort.bsteam < ./files/wlist0 > wlist0.bsteam <br>
**\$** diff -s -u wlist0.mine wlist0.bsteam

**Task Notes:**
- Helpful manual pages: **feof(3), ferror(3), fflush(3), fgetc(3), fgets(3),fputs(3), getchar(3), malloc(3), qsort(3), realloc(3), strchr(3), strcmp(3), strlen(3)**
- All functions used for input/output (except **feof(3)**, **ferror(3)**) set **errno**, even if this may not be clear from the manual pages.
- All error messages are to be output on the standard error channel (*stderr*). The standard output (*stdout*) only the sorted word list is to be output.
- **Ctrl-D** sends **EOF** to the application and thus terminates the input.
