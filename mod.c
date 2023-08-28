#include "monint.h"

/**
 *op_mod - computes the remainder of the second top element of the
 *    stack by the top element of the stack
 * @stack: stack given by main
 * @idx: number of lines
 *
 * Return: void
 */
void op_mod(stack_t **stack, unsigned int idx)
{
	int res;

	if (!(stack || *stack || (*stack)->next))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", idx);
		exit(EXIT_FAILURE);
		return;
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", idx);
		exit(EXIT_FAILURE);
		return;
	}

	res = ((*stack)->next->n) % ((*stack)->n);
	op_pop(stack, idx);
	(*stack)->n = res;
}
