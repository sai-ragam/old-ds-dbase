/*
stack implementation using singly linked list

dsjk
*/


#include<stdlib.h>
#include<stdio.h>
#include "ll.h"

#define MAX_STACK_SIZE 10

int pop(list_element **phead);   		// removes one element from the top, return the value
void push(list_element **phead,int value);  	// inserts one element
void print_stack(list_element *head);		// prints stack values
int stack_size(list_element *head);		// returns stack size
int get_top_value(list_element *head);		// returns stack head value

int pop(list_element **phead)
{
	if( stack_size(*phead) == 0)
	{
		printf("stack empty\n");
		return -1;
	}

	int pop_value =  get_value_n(*phead, 1);
	delete_n(phead, 1);
	return pop_value;
}


void push(list_element **phead, int value)
{
	if( stack_size(*phead) >= MAX_STACK_SIZE )
	{
		printf("stack full \n");
		return;
	}

	insert_n(phead, value, 1);
}


void print_stack(list_element *head)
{
	print_list(head);
}


int stack_size(list_element *head)
{
	return length_list(head);
}


int get_top_value(list_element *head)
{
	if(stack_size(head) == 0)
	{
		printf(" stack empty \n");
		return -1;
	}
	 
	return get_value_n(head,1);
}




int main()
{
	
	list_element *head=NULL;
	int op,value;

	while(1)
	{
		printf(" select stack ops : 1)PUSH; 2)POP; 3)GET HEAD VALUE; 4)DISPLAY; 5)STACK_SIZE; 6)DELETE STACK, EXIT; \n");
		scanf("%d",&op);
	
		switch(op)
		{
			case 1:
			printf(" enter value  : \n");
			scanf("%d",&value);
			push(&head, value);
			break;
			
			case 2:
			value = pop(&head);
			if(value != -1)
			{
				printf(" poped element : %d \n", value);
			}
			break;
		
			case 3:
			value = get_top_value(head);
			if(value != -1)
			{
				printf(" head value : %d \n", value);
			}
			break;
		
			case 4:
			print_stack(head);
			break;
		
			case 5:
			printf(" stack size : %d \n", stack_size(head));
			break;	
	
			case 6:
			free_list(&head);
			printf(" deleted stack, exiting \n");
			return 0;
	
			default:
			printf(" invalid option, try again \n");
			break;		
	
		}	
	}
	
	return 0;
}
