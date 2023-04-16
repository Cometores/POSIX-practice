# palim
**Parallel Line Matcher** program that prints the number of lines containing a given string in regular files.

The program is called as follows:
> **\$** ./palim \<string> \<max-grep-threads> \<trees...>


**Basic Functionality**:
- **crawl thread** - The directory trees passed as parameters are recursively searched in a separate thread.
- **grep thread** - A separate thread is created for each found regular file **pthread_create(3)**
	- goes through its contents line by line **fopen(3)**, **fgets(3)**, **strstr(3)**
	- The number of active grep threads is limited by **max-grep-threads**. If that number of threads is already active, the system passively waits for a thread to terminate before creating another thread.
- During execution, the program should **output** the following information in one line:
	- **lineHits** - number of lines containing hits
	- **lines** - number of lines searched
	- **fileHits** - number of files with at least one hit
	- **files** - number of files searched
	- **dirs** - number of directories searched
	- **activeGrepThreads** - number of currently active grep threads.
- The output of the statistics should be continuously updated by the main thread (main()) as soon as any information changes. In the meantime the main thread waits passively for changes. For this it has to be synchronized with the other threads in a suitable way. other threads in a suitable way.
 - When accessing global data structures, care must be taken to ensure correct synchronization. Slow operations (e.g. **printf(3)**) must not be executed in critical sections.
 - For synchronization the given semaphore module (*sem.o*, *sem.h*) is to be used.


 **Program structure**:
- **main()** initializes the necessary data structures, **starts one crawl thread per given directory tree**, and then passively waits for statistics updates. Once all threads have terminated, main() takes over the cleanup/release of the remaining resources.
- **void\* processTree(void\* path)** is the entry point for the crawl threads and calls the **processDir()** function to browse path.
- **void\* processDir(char\* path)** iterates over the individual elements in the given path and calls the function **processEntry()** for each element found.
- **void\* processEntry(char\* path, struct dirent\* entry)** checks whether the given element entry is a regular file or a directory:
	- For directories **processDir()** is called for recursive descent.
	- For regular files, a separate **grep thread** is created in each case, which calls the function **processFile()** to search the file. If **max-grep-threads threads** are already running, then the creation of a new thread is delayed.
	- Entries that are neither regular file nor directory are **ignored**.
- **void\* processFile(void\* path)** is the entry point for the grep threads and searches the given file path line by line for the string passed by command line.
- The four **process\*()** functions each update the corresponding statistics.


**Task Notes:**
- The cursor can be reset to the beginning of the line by outputting the character *'\r'*.
- The output of a string can be forced using **fflush(3)**.
- All created threads should be executed in detached-state **pthread_detach(3)**.
- To compile the program the additional compiler flag **-pthread** is necessary.