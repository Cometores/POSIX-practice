# alsym
**All Symbolic links** program that displays the names of all symbolic links files in the current directory.

**Task Notes**
- Using **lstat(2)** system call to examine file attributes.
    - **stat(2)** follows a symbolic link and shows target information
- Using **opendir(3)** and **readdir(3)** 
- Define the data type - **inode(7)**