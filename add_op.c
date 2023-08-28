#include "monint.h"

/**
 * op _add -  adds the first two nodes of the stack
 * @stack: main function stack
 * @idx: number of lines
 *
 * Return: void
 */
void op_add(stack_t **stack, unsigned int idx)
{
	int tot;

	if (!(stack || *stack || (*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", idx);
		exit(EXIT_FAILURE);
	}

	tot = ((*stack)->next->n) + ((*stack)->n);
	op_pop(stack, idx);
	(*stack)->n = tot;
}
