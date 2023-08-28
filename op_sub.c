#include "monint.h"

/**
 * sub_op -  substracts the first node from the second node
 * @stack: stack given by main functiom
 * @idx: number of lines
 *
 * Return: void
 */
void sub_op(stack_t **stack, unsigned int idx)
{
	int res = 0;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", idx);
		exit(EXIT_FAILURE);
	}

	res = ((*stack)->next->n) - ((*stack)->n);
	op_pop(stack, idx);
	(*stack)->n = res;
}
