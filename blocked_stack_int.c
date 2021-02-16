#include "blocked_stack_int.h"

// create new block and link it to Previous_block and make new block -> current block in stack
void create_block(stack_int *stack){
	block *b;
	b = (block *) malloc( sizeof(block) );  // create new block in stack
	b->values = (int *) malloc(sizeof(int) * stack->block_size); // allocates memory for block values
	stack->top = 0;    // set stack top to 0 which index to next store location in block values
	if (stack->current_block == NULL){   // this mean this is frist block
		b->Previous_block = NULL;  // make Previous block NULL for the first block 
	} else{
		b->Previous_block = stack->current_block; // make current filled block -> Previous block
		stack->size = stack->size + stack->block_size;  // increase stack size with old block_size
	}
	stack->current_block = b;   // make new block -> current block in stack
	
}

/*create new stack structure
block_size is stack size
Stack_int implementation in Stack_int.h
*/
stack_int * new_blocked_stack_int(int block_size){
	stack_int *stack;   //create pointer to Stack
	stack = (stack_int *) malloc( sizeof(stack_int) ); // allocates memory for stack
	stack->block_size = block_size;  // set stack block size
	stack->size = 0;     // set size to 0
	stack->current_block = NULL;  // used in next function to show that created block will be first in stack
	create_block(stack);  //create new block
	
	return stack;      // return pointer to stack which you create
	
}

/* check if Stack is Empty
if there are Previous block , this mean stack is not empty
else when top == 0 ,this mean the Stack is empty
return: 1 if true
        0 if false
*/
int stack_int_isempty(stack_int *s){
	block *temp_block = NULL;
	temp_block = s->current_block->Previous_block;
	if(temp_block == NULL){
		if(s->top == 0){
			return 1;
		} else {
			return 0;
		}
	} else{
		return 0;
	}
	
}

/* this function return the Size of stack
we will add stack top to stack size
where: stack top point to number of elements in current block
       stack size point to number of elements in filled blocks
*/
int stack_int_size(stack_int *s){
	
	return s->size + s->top;
}

// push number into Stack
void stack_int_push(stack_int *s, int x){
	if(s->top == s->block_size){    // when Stack block is full , Stack top will equal to block Size
		create_block(s);	  // create new block ,make top = 0
	} 
	*(s->current_block->values + s->top) = x;   // store number in values array
	s->top++;   // increase Stack top to index to next store location in block values
	
}

// pop Stack
void stack_int_pop(stack_int *s){
	s->top--;    // make Stack top index to Previous store location in block's values
	if(s->top == 0){  // when stack top == 0 this mean block is empty 
		if(s->current_block->Previous_block == NULL){ // if there is no Previous block in stack
			s->top = 0;  // make top = 0 to index to next store location in current block's values
		} else{
			block *temp_block; // we create pointer to block to store current block in
			temp_block = s->current_block;
			s->current_block = temp_block->Previous_block;  // make current block point to Previous_block
			s->top = s->block_size;  // make top point to the top of Previous_block 
			s->size = s->size - s->block_size; //decrease number of elements in filled blocks
			free(temp_block->values); //free memory used by block's values
			free(temp_block);  // free memory used by block structure
			
		}
	}
		
}

// this function return Stack top value without pop stack
int stack_int_top(stack_int *s){
	int i = s->top - 1;  // remember top to index to next store location in block's values 
 						//so decrease it to index last stored value
	
	return *(s->current_block->values + i);  // return last stored value
}

// display Stack values from top to bottom
void stack_int_display(stack_int *s){
	int i;
	block *temp_block, *b;
	b = s->current_block;
	
	i = s->top;
	do{
		
		temp_block = b->Previous_block;
		
		printf(" ------ \n");
		while(i > 0){
			i--;
			printf("| %4d | \n",*(b->values + i));
			printf(" ------ \n");
		}

		i = s->block_size;
		b = temp_block;

	} while(temp_block != NULL);
	
}


//deallocates the memory space used by Stack 
void stack_int_release(stack_int *s){
	free(s);
}