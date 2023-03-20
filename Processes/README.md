# excufoe
**Execute For Each** program, which executes a command with each of the passed parameters once.
> **\$** ./excufoe \<program> <arguments...>

**Goals:**
- Creating child processes by fork call.
- Replacing a created process with an exec process.

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

