#include "monint.h"

/**
 * op _mul - divides the next top value by the top value
 * @stack: stack given by main
 * @idx: number of lines
 *
 * Return: void
 */
void _mul(stack_t **stack, unsigned int idx)
{
	int res;

	if (!(stack || *stack || (*stack)->next))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", idx);
		exit(EXIT_FAILURE);
		return;
	}

	res = ((*stack)->next->n) * ((*stack)->n);
	op_pop(stack, idx);
	(*stack)->n = res;
}
