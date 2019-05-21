#include "stack_int.h"



int main(void){
	
	linked_list_int stack=create_empty_stack();
	
	stack=push(stack,1);
	stack=push(stack,5);
	stack=push(stack,3);
	print_stack(stack);
	deallocate_stack(stack);


	return 0;
}
