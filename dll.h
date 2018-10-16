/*
doubly linked list header file

djsk
*/


#include<stdio.h>
#include<stdlib.h>


struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
};

typedef struct Node list_element;

void insert( list_element **phead, int value);			//insert at the end
void delete( list_element **phead, int value);			//delete based on value search, delete all instances of value
void print_list( list_element *head);				//print entire list
void free_list( list_element **phead);				//free entire list
void insert_n( list_element **phead, int value, int position);	//insert based on position (starting:1)
void delete_n( list_element **phead, int position);		// delete based on position (starting:1)
int length_list ( list_element *head);				// returns length of dll
int search_list ( list_element *head, int value);		// search list for value, return position (starting:1)
void reverse_list( list_element **phead);			// reverse given dll list


