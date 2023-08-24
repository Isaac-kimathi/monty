#include "monint.h"
/**
 * nd_add - adds node to the head of the stack
 * @head: head of the stack
 * @n: new int value
 * Return: void
 */
void nd_add(stack_t **head, int n)
{
	stack_t *nw, *kl;

	kl = *head;
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (kl)
		kl->prev = nw;
	nw->n = n;
	nw->next = *head;
	nw->prev = NULL;
	*head = nw;
}
