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
> **\$** ./prog "ls -f"