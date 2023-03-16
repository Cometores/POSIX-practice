# lilo
Implementation of the **Last In Last Out** list, which operates positive numbers and provides the following functions:
- ***int insertElement(int value)***: Adds a value to the list if it does not already exist. If successful, the function returns the inserted value, otherwise the value -1.
- ***int removeElement(void)***: Takes the oldest value from the list and returns it. If there is no value in the list, -1 is returned.

# filo
Implementation of the **First In Last Out** list, which operates positive numbers and provides the following functions:
- ***int insertElement(int value)***: Adds a value to the list if it does not already exist. If successful, the function returns the inserted value, otherwise the value -1.
- ***int removeElement(void)***: Takes the last inserted value from the list and returns it. If no value is present in the list, -1 is returned.

## Task Notes:
- Helpful manual pages: **malloc(3)**, **free(3)**
- **Do not implement any list functionality in the main() function.** All operations necessary for list management must be performed in insertElement() and removeElement. However, you can extend the main() function to test your implementation.
- The header of the list is to be created as a global variable.
- The attempt to add a negative number to the list should be prevented and considered as an error.
- If an error occurs during the execution of a used function (e.g. *malloc(3)*), no error messages are to be output - but the error must be handled sensibly according to the task.