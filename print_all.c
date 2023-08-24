#include "monint.h"
/**
 * pall_s - prints all values in a stack from top to bottom
 * @head: stack head
 * @counter: iterator
 * Return: void
 */
void pall_s(stack_t **head, unsigned int idx)
{
	stack_t *q;
	(void)idx;

	q = *head;
	if (q == NULL)
		return;
	while (q)
	{
		printf("%d\n", q->n);
		q = q->next;
	}
}
