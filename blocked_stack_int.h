#ifndef BLOCKED_STACK_INT_H
#define BLOCKED_STACK_INT_H
#include <stdlib.h>
#include <stdio.h>

typedef struct block{
	int *values;  // pointer to block location in memory which use block_size to
				  // create memory block
	struct block *Previous_block;  // pointer to Previous block in stack,it will
 									// be null if this block was frist block in stack 
} block; 

typedef struct myStack{
	int top;   // index to next store location in block values and number of elements in current block
	int size;   // number of elements in filled blocks
	int block_size;
	block *current_block;    // pointer to current block which values store in 
									//	it in this time
} stack_int;


stack_int * new_blocked_stack_int(int block_size);
int stack_int_isempty(stack_int *s);
int stack_int_size(stack_int *s);
void stack_int_push(stack_int *s, int x);
void stack_int_pop(stack_int *s);
int stack_int_top(stack_int *s);
void stack_int_display(stack_int *s);
void stack_int_release(stack_int *s);
#endif