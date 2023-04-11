# alsym
**All Symbolic links** program that displays the names of all symbolic links files in the current directory.

**Task Notes**
- Using **lstat(2)** system call to examine file attributes.
    - **stat(2)** follows a symbolic link and shows target information
- Using **opendir(3)** and **readdir(3)** 
- Define the data type - **inode(7)**




# halde
A simple implementation of **free memory management**, which:
- replaces **malloc(3)**, **calloc(3)**, **realloc(3)** and **free(3)** 
- manages **1 MB of memory** using a simple **linked list**. 
- The individual list items that contain the size of the memory area being managed are stored at the beginning of the corresponding memory area.

**Basic Functionality**:
- To be completed

**Testing**
- Tests for **malloc** and **free**
    - The test example in the file test.c. 
    - It consists of four consecutive **malloc** calls, **freeing** the requested memory areas, and four more **malloc** calls. 
    - At least one of the extreme cases described on the man page **malloc(3)** must be called .
        - indicate which extreme case you are testing in the text comment above the call. 
    - All memory areas must be freed with **free()** when testing is finished. 
    - After each **malloc** and **free** call the function **printList** is to be called, which prints the internal state of the freespace list.
        - do not use printf(3)/fprintf(3)
    - compare the output of the **test** and **test-ref** programs. The output does not have to match exactly - it is enough if the number of output list items matches exactly, and the total amount of free memory matches approximately.