#include "monint.h"

/**
 * pushx_add node to a stack
 * @head: head of a stack
 * idx: the number of a line
 * Return: void
 */
void pushx(stack_t **stack, unsigned int idx)
{
	stack_t *nw_nd;

	nw_nd = malloc(sizeof(stack_t));
	if (!nw_nd)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nw_nd->n = idx;
	nw_nd->prev = NULL;
	nw_nd->next = *stack;
	
	if (*stack)
	{
		(*stack)->prev = nw_nd;
	}
	*stack = nw_nd;
}

/**
 * pall_s - prints all values in a stack from top to bottom
 * @head: stack head
 * @counter: iterator
 * Return: void
 */
void pall_s(stack_t **stack, unsigned int idx)
{
	stack_t *q;

	(void)idx;
	q = *stack;
	if (q == NULL)
		return;
	while (q)
	{
		printf("%d\n", q->n);
		q = q->next;
	}
}
