# dynamic-stack-data-structure
 Dynamic memory allocation implementation of a stack data structure in in ANSII C.
 It is not simple dynamic stack, it is data block-based dynamic stack.
 # Features:
 - create stack and allocate memory for  integer data block to work on it.
 - the user is able to specify the size of block in the creation of stack.
 - the block size will remain constant for the lifetime of the stack instance.
 - the stack continue to push data in block until the block become full, then the stack dynamically create new block and allocate memory for it.
 - the stack pop data from data block. if data block is empty and there is Previous data block in stack, the stack will point to the Previous data block and free the memory allocated for the current data block in order to avoid memory leak.
 - get Stack top value without pop stack. 
 - display Stack values from top to bottom.
 - implement singly linked list to link data blocks together.

# Files:
- blocked_stack_int.c: implementation of data block-based dynamic stack.
- blocked_stack_int.h: block-based dynamic stack header file.
- demo_blocked_stack_int: a demo code.
- build.bat: windows batch file contain gcc command line to compile demo code.
 
