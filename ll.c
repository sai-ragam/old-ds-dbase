/* 
linked list implementation
double pointers used in case of head modification

djsk
*/


#include "ll.h"


void insert(list_element **phead, int value)
{
	
	if(phead == NULL)
	{
		return;
	}
	
	list_element *new=malloc(sizeof(list_element)), *iterator;
	new->data = value;
	new->next = NULL;
	
	if(*phead == NULL)
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
	
}


void delete(list_element **phead, int value)
{
	
	if(phead == NULL)
	{
		return;
	}
		
	list_element *iterator=*phead,*temp,*prev=*phead;
	
	while( iterator )
	{	
		if ( iterator->data == value )
		{
			if ( iterator == *phead )
			{
				*phead = iterator->next;
				prev = *phead;
			}
			else
			{
				prev->next = iterator->next;
			}
			
			temp = iterator;
			iterator = iterator->next;
			free(temp);
		}
		else
		{
			prev = iterator;
			iterator = iterator->next;
		}
	}
}


void print_list(list_element *head)
{
	printf("\n----------------------------------------------\n");

	if (head == NULL)
	{
		printf("empty list \n");
	}
	
	list_element *iterator;
	
	for(iterator=head;iterator!=NULL;iterator=iterator->next)
	{
		printf(" value : %d \n",iterator->data);
	}
	
	printf("\n-----------------------------------------------\n");
}


void free_list(list_element **phead)
{
	list_element *temp;
	
	while( *phead )
	{
		temp = (*phead)->next;
		free(*phead);
		*phead=temp;
	}
}


void insert_n(list_element **phead, int value, int position)
{
	int counter = 1;
	
	if( phead == NULL )
	{
		return;
	}
	
	if( position < 1 )
	{
		return;
	}
	
	list_element *new=malloc(sizeof(list_element)), *iterator;
	new->data = value;
	new->next = NULL;
	
	if( *phead == NULL )
	{
		*phead = new;
		return;
	}
	
	if( position == 1)
	{
		new->next = *phead;
		*phead = new;
		return;
	}
	
	iterator = *phead;
	
	while( iterator->next && counter<(position-1))
	{
		iterator = iterator->next;
		counter++;
	}
	
	if ( iterator->next )
	{
		new->next = iterator->next;
	}

	iterator->next = new;
	
}


void delete_n(list_element **phead, int position)
{
	
	if(phead == NULL)
	{
		return;
	}
		
	list_element *iterator=*phead,*temp,*prev=*phead;
	int counter=1;
	
	while( iterator )
	{	
		if ( counter == position )
		{
			if ( iterator == *phead )
			{
				*phead = iterator->next;
				prev = *phead;
			}
			else
			{
				prev->next = iterator->next;
			}
			
			temp = iterator;
			iterator = iterator->next;
			free(temp);
			return;
		}
		else
		{
			counter++;
			prev = iterator;
			iterator = iterator->next;
		}

	}
}


int length_list(list_element *head)
{
	int length;
	
	for(length=0; head!=NULL; head=head->next, length++);
	
	return length;
}


int search_list(list_element *head, int value)
{
	int position = 1;
	list_element *iterator = head;
	
	while( iterator->next )
	{
		if( iterator->data == value )
		{
			return position;
		}
		
		position++; 
		iterator = iterator->next;
	}
	
	return -1;
}


void reverse_list ( list_element **phead)
{
	list_element *iterator=*phead, *prev=NULL, *next=NULL;
	
	while( iterator )
	{
		next = iterator->next;
		iterator->next = prev;
		prev = iterator;
		iterator = next;
	}
	
	*phead = prev;
}

int get_value_n(list_element *head, int position)
{
	list_element *iterator = head;
	int counter = 1;
	
	while (iterator)
	{
		if(counter == position)
		{
			return iterator->data;
		}
		
		counter++;
		iterator = iterator->next;
	}
	
	return -1;
}
	
		
