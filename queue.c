/*
queue implementation using singly linked list

dsjk
*/


#include<stdlib.h>
#include<stdio.h>
#include "ll.h"

#define MAX_QUEUE_SIZE 10

int dequeue(list_element **phead);   		// removes one element from the end, returns the value
void enqueue(list_element **phead,int value);  	// inserts one element to the front
void print_queue(list_element *head);		// prints queue values
int queue_size(list_element *head);		// returns queue size
int get_front_value(list_element *head);	// returns queue head value
int get_end_value(list_element *head);

int dequeue(list_element **phead)
{
	int size = queue_size(*phead);
	if(size == 0)
	{
		printf("queue empty\n");
		return -1;
	}

	int pop_value =  get_value_n(*phead, size);
	delete_n(phead, size);
	return pop_value;
}


void enqueue(list_element **phead, int value)
{
	if( queue_size(*phead) >= MAX_QUEUE_SIZE )
	{
		printf("queue full \n");
		return;
	}

	insert_n(phead, value, 1);
}


void print_queue(list_element *head)
{
	print_list(head);
}


int queue_size(list_element *head)
{
	return length_list(head);
}


int get_front_value(list_element *head)
{
	if(queue_size(head) == 0)
	{
		printf(" queue empty \n");
		return -1;
	}
	 
	return get_value_n(head,1);
}


int get_end_value(list_element *head)
{
	int size = queue_size(head);
	if(size == 0)
	{
		printf(" queue empty \n");
		return -1;
	}
	
	return get_value_n(head,size);
}


int main()
{
	
	list_element *head=NULL;
	int op,value;

	while(1)
	{
		printf(" select stack ops : 1)ENQUEUE; 2)DEQUEUE; 3)GET FRONT VALUE; 4)GET END VALUE; 5)DISPLAY; 6)QUEUE_SIZE; 7)DELETE QUEUE, EXIT; \n");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1:
			printf(" enter value  : \n");
			scanf("%d",&value);
			enqueue(&head, value);
			break;
			
			case 2:
			value = dequeue(&head);
			if(value != -1)
			{
				printf(" dequeued element : %d \n", value);
			}
			break;
		
			case 3:
			value = get_front_value(head);
			if(value != -1)
			{
				printf(" front value : %d \n", value);
			}
			break;
		
			case 4:
			value = get_end_value(head);
			if(value != -1)
			{
				printf(" end value : %d \n", value);
			}
			break;
			
			case 5:
			print_queue(head);
			break;
		
			case 6:
			printf(" queue size : %d \n", queue_size(head));
			break;	
	
			case 7:
			free_list(&head);
			printf(" deleted queue, exiting \n");
			return 0;
	
			default:
			printf(" invalid option, try again \n");
			break;		
	
		}	
	}
	
	return 0;
}
