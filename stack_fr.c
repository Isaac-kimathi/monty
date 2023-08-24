#include "monint.h"
/**
 * free_dlnk_lst - frees a doubly linked list
 * @head: head of the stack
 */
void free_dlnk_lst(stack_t *head)
{
	stack_t *qw;

	qw = head;
	while (head)
	{
		qw = head->next;
		free(head);
		head = qw;
	}
}
