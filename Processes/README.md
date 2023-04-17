# listrun
Program which executes a command once with each of the passed parameters **as a list**.
> **\$** ./listrun \<program> \<arguments...>

**Goals:**
- Creating child processes by **fork** call.
- Replacing a created process with an **exec** process.

Expects call like:
> **\$** ./listrun echo this is a test

> this
>
> is
>
> a
>
> test

# excufoe
**Execute For Each** program, which executes a command with each of the passed parameters **as a string** once. The program is identical to **listrun** except that the program and parameters are passed as a string.
> **\$** ./excufoe "\<program> \<arguments...>"

**Goals:**
- Using **strtok(3)**.

Expects call like:
> **\$** ./excufoe "echo this is a test"

> this
>
> is
>
> a
>
> test

or 
> **\$** ./excufoe "ls -f"



# party
**PARallel Task Player**. A program that executes commands sent through the command line in parallel. A maximum of n commands can be executed simultaneously. The upper bound n is also passed through the command line. 

Expects call like:
> **\$** ./party 2 ”sleep 5” ”ls -ash /” ”ps aux” ”tar -xvf file.tar”



# hupsi
**Highly Unreliable Parallel Software Igniter**. Program that reads commands line by line (one command per line, lines separated with '\n') from standard input and executes them in parallel. The maximum number n of commands executed in parallel is to be passed as a command line argument.

Expects call like:
> **\$** ./hupsi 2 < commands.txt



# clash
**C language apprentice’s shell** that runs programs passed through stdin. 

**Basic Functionality**:
- **clash** prints the current working directory **getcwd(3)** followed by a colon as prompt symbol and then reads in a line from standard input.
- The read line is split into command names and arguments
	- spaces and tabs are used as separators **strtok(3)**
- The command is then executed in a newly created process **fork(2)** with correctly passed arguments **exec(3)**.
- clash waits for **foreground processes** to terminate the **waitpid(2)** command execution and prints the exit status along with the associated command line. The output should look like the following:
	- > /Processes/clash/: echo test <br>
	  > test <br>
	  > Exitstatus [echo test] = 0
    - Nach der Ausgabe des Exitstatus nimmt die Shell wieder eine neue Eingabe entgegen.
- If a command line ends with the token **"&"**, the command is executed in a **background process**. In this case, the shell does not wait for the process to end, but immediately displays a new prompt to accept further commands.
	- Each time before a new prompt is displayed, the shell collects all background processes **(zombies)** that have been terminated up to this point and outputs their exit status analogous to the foreground processes. For this purpose, when creating a background process, note its PID and command line in a linked list. 
- clash terminates on signaling end-of-file (Ctrl-D) on the standard input channel.

**Expanded functionality**:
- **Directory change** 
	- If **"cd"** is entered as the command, the clash-Process should set its working directory to the path specified in the following argument.
	- Implementation a directory change **chdir(2)**.
- **Display running background processes**
	- Command **"jobs"**, which prints the PID and command line of all currently running background processes to the standard output in one line each. 
	- For this it is necessary to extend the given plist.c module by the function **walkList()**, which calls a callback function for each element of the chained list.
- **Makefile**
	- Create a Makefile suitable for the task, which supports the targets all, clean and clash. Always use intermediate products (e.g. plist.o). The Makefile should work without built-in rules (start **make(1)** with the -rR options). 
	- compiler flags: -std=c11 -pedantic -Wall -Werror D_XOPEN_SOURCE=700

**Task Notes:**
- File *clash* is the correct solution to the comparison and testing task.
- File *plist.o* - proper implementation of a linked list for comparison and testing.
- The maximum length of an input line (including \n) that your clash should be able to handle is 1337 bytes. If more characters are entered, the entire (overlong) line should be discarded with a warning.
- Calling the **getcwd(3)** function with NULL as first parameter (e.g. getcwd(NULL, 0);) is not part of the POSIX specification and thus must not be used