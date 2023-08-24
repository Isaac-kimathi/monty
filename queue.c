#include "monint.h"
/**
 * queue_add - add node to the tail of the stack
 * @n: new int value to add
 * @head: head of the stack
 * Return: no void
 */
void queue_add(stack_t **head, int n)
{
	stack_t *nw, *ty;

	ty = *head;
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		printf("Error\n");
	}
	nw->n = n;
	nw->next = NULL;
	if (ty)
	{
		while (ty->next)
			ty = ty->next;
	}
	if (!ty)
	{
		*head = nw;
		nw->prev = NULL;
	}
	else
	{
		ty->next = nw;
		nw->prev = ty;
	}
}
