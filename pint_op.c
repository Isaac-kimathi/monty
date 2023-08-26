#include "monint.h"

/**
 * op_pint - prints the value at the top of the stack, followed by a new line
 * @stack: double pointer to address of the stack
 * @idx: integer iterator
 * Return: void
 */
void op_pint(stack_t **stack, unsigned int idx)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", idx);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
