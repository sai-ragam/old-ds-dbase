/*
singly linked list header file

djsk
*/


#include<stdio.h>
#include<stdlib.h>


struct Node
{	
	int data;
	struct Node *next;
};

typedef struct Node list_element;

void insert( list_element **phead, int value);			//insert @ end
void delete( list_element **phead, int value);			//search and delete all instances of "value" in list
void free_list (list_element **phead);				//deletes entire list
void print_list (list_element *head);				//prints all elements of the list 
void insert_n( list_element **phead, int value, int position);	//insert @ postion (starting : 1)
void delete_n ( list_element **phead, int position);		//delete node at postion (starting : 1)
int length_list ( list_element *head);				//returns lenght of ll
int search( list_element *head, int value);			//search for "value", return position
void reverse_list ( list_element **phead);			//reverse given linked list
int get_value_n( list_element *head, int position);             //get data at a position (starting : 1)

