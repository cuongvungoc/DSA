#include <stdio.h>
#include "linkedlist.h"

int main()
{
	struct node_t* head = NULL;
	push (&head, 5);
    push (&head, 4);
    push (&head, 3);
    push (&head, 2);
    push (&head, 1);
    append (&head, 6);
    append (&head, 7);
    append (&head, 8);
    insert (head->next->next, 9);
    printList(head);
    printf("\n");
    delete_at (&head, 1);
    delete_by_key (&head, 5);


	// Function call
	printList(head);

	return 0;
}