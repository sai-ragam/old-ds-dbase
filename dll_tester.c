/*
doubly linked list tester

djsk
*/


#include "dll.h"


int main()
{
	
	list_element *head = NULL;
	int i;
	
	for (i=0;i<15;i++)
	{
		insert(&head,i);
	}
	
	print_list(head);
	
	for(i=0;i<15;i+=3)
	{
		delete(&head,i);
	}
	
	print_list(head);
	
	insert_n(&head,2,3);
	print_list(head);
	
	delete_n(&head,6);
	print_list(head);
	
	reverse_list(&head);
	print_list(head);
	
	printf("%d %d %d \n", search_list(head,4), search_list(head,13), search_list(head,19));
	
	free_list(&head);
	print_list(head);
	
	return 0;
}
