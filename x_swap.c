#include "monint.h"

/**
 * x_swap - swaps data from top to previous
 * @stack: stack sourced by main function
 * @idx: number of lines
 *
 * Return: void
 */
void x_swap(stack_t **stack, unsigned int idx)
{
	stack_t *fx = NULL;
	int w = 0;

	if (!((stack) || (*stack) || ((*stack)->next)))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", idx);
		exit(EXIT_FAILURE);
	}
	fx = *stack;
	w = fx->n;
	fx->n = w;

	fx->n = fx->next->n;
	fx->next->n = w;
}
