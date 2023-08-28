#include "monint.h"

/**
 * op_pop - removes element at the top of the stack
 * @stack: stack given by main function
 * @idx: line count.
 *
 * Return: void
 */
void op_pop(stack_t **stack, unsigned int idx)
{
	stack_t *dd = NULL;

	if (!stack || !*stack)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", idx);
		exit(EXIT_FAILURE);
	}

	dd = (*stack)->next;
	free(*stack);
	*stack = dd;
	if (!*stack)
		return;
	(*stack)->prev = NULL;
}
