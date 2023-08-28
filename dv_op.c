#include "monint.h"

/**
 * op_div - divides the next top value by the top value
 * @stack: stack given by main
 * @idx: number of strings
 *
 * Return: void
 */
void op_div(stack_t **stack, unsigned int idx)
{
	int res;

	if (!(stack || *stack || (*stack)->next))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", idx);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", idx);
		exit(EXIT_FAILURE);
		return;
																}

	res = ((*stack)->next->n) / ((*stack)->n);
 	op_pop(stack, idx);
	(*stack)->n = res;
}
