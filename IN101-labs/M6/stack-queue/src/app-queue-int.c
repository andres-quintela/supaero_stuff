#include "queue_int.h"

int main(void){
	
	linked_list_int queue=create_empty_queue();
	
	queue=enqueue(queue,5);
	
	queue=enqueue(queue,1);
	
	queue=enqueue(queue,6);
	queue=enqueue(queue,7);
	queue=enqueue(queue,2);
	queue=enqueue(queue,9);

	
	
	print_queue(queue);
	printf("new queue\n");
	
	linked_list_int new_queue=dequeue(queue);
	print_queue(new_queue);
	return 0;

	}
