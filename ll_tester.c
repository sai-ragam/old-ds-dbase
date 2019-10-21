/*
singly linked list tester

djsk
*/


#include"ll.h"


int main()
{
	
	list_element *head = NULL;
	
	int i;
	
	for(i=0;i<=15;i++)
	{
		insert(&head,i);
	}
	
	print_list(head);
	
	for(i=0;i<=15;i+=3)
	{
		delete(&head,i);
	}
	

	print_list(head);
	
	insert_n(&head,2,3);	
	print_list(head);
	
	delete_n(&head,3);
	delete_n(&head,length_list(head));
	print_list(head);

	reverse_list(&head);
	print_list(head);	
	
	free_list(&head);
	print_list(head);

	return 0;	
}
