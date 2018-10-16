/*
doubly linked list implementation
double pointers used in case of head modification

djsk
*/

#include "dll.h"


void insert( list_element **phead, int value)
{
	if (phead == NULL)
	{
		return;
	}
	
	list_element *new,*iterator;
	new = malloc(sizeof(list_element));
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	
	if ( *phead == NULL )
	{
		*phead = new;
		return;
	}
	
	iterator = *phead;
	while( iterator->next )
	{
		iterator = iterator->next;
	
	}
	
	iterator->next = new;
	new->prev = iterator;
}


void delete ( list_element **phead , int value)
{
	if (phead == NULL)
	{
		return;
	}
	
	list_element *iterator=*phead,*temp;
			
	while( iterator )
	{
		 if (iterator->data  == value)
		 {
	
			if (iterator->next)
			{
				iterator->next->prev = iterator->prev;
			}
			if( iterator == *phead)
			{
				*phead = iterator->next;
			}
			else
			{
				iterator->prev->next = iterator->next;
			}
		
			temp = iterator;
			iterator = iterator->next;	
			free(temp);
	
		}
		else
		{	
	        	 iterator = iterator->next;
		}
	}
	
	
}

		
void print_list( list_element *head)
{
	
	printf("\n-----------------------------------------------------\n");

	list_element *iterator;
	
	if( head == NULL)
	{
		printf("list empty \n");
	}

	for (iterator=head; iterator!=NULL ; iterator=iterator->next)  //alternate iteration technique using for loop
	{
		printf("Value : %d \n", iterator->data);
	}

	printf("\n-----------------------------------------------------\n");

}


void free_list( list_element **phead)
{
	
	list_element *temp;
	
	while( *phead )
	{
		temp = (*phead)->next;
		free(*phead);
		*phead = temp;
	}
}


void insert_n( list_element **phead, int value, int position)
{
	
	if (phead == NULL)
	{
		return;
	}
	
	int counter=1;
	list_element *new,*iterator;
	new = malloc(sizeof(list_element));
	new->data = value;
	new->next = NULL;
	new->prev = NULL;
	
	if ( *phead == NULL )
	{
		*phead = new;
		return;
	}
	
	if ( position == 1)	
	{
		new->next = *phead;
		*phead = new;
		return;
	}
	
	iterator = *phead;
	while( iterator->next && counter<(position-1) )
	{
		iterator = iterator->next;
		counter++;
	}

	if( iterator->next )
	{
		new->next = iterator->next;
		iterator->next->prev = new;
	}
		
	iterator->next = new;
	new->prev = iterator;

}


void delete_n( list_element **phead, int position)
{
	
	if (phead == NULL)
	{
		return;
	}
	
	list_element *iterator=*phead,*temp;
	int counter = 1;
			
	while( iterator )
	{
		 if ( counter == position )
		 {
	
			if (iterator->next)
			{
				iterator->next->prev = iterator->prev;
			}
			if( iterator == *phead)
			{
				*phead = iterator->next;
			}
			else
			{
				iterator->prev->next = iterator->next;
			}
		
			temp = iterator;
			iterator = iterator->next;	
			free(temp);
			return;
	
		}
		else
		{	
			counter++;
	        	iterator = iterator->next;
		}
		
	}
	
}


int length_list ( list_element *head)
{
	int length;
	
	for(length=0; head!=NULL; head=head->next, length++);
	
	return length;
}


int search_list ( list_element *head, int value)
{
	int position = 1;
	list_element *iterator = head;
	
	while( iterator->next )
	{
		if(iterator->data == value )
		{
			return position;
		}
		
		position++;
		iterator = iterator->next;
	}
	
	return -1;
}


void reverse_list( list_element **phead)
{
	list_element *iterator=*phead, *next, *prev; 

	while ( iterator )
	{
		next = iterator->next;
		iterator->next = iterator->prev;
		iterator->prev = next;
		prev = iterator;
		iterator = next;		
	}
	
	*phead = prev;

}


