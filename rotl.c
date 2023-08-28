#include "monint.h"

/**
 * rotl - rotates the first element of the stack t the bottom of the stack
 * @stack: stack head
 * @idx: line count
 *
 * Return: void
 */
void rotl_op(stack_t **stack, unsigned int idx)
{
	stack_t *top;
	stack_t * bottom;

	(void) idx;
	if (!stack || !*stack || !(*stack)->next)
		return;

	top = bottom = *stack;

	while (top->next)
		top = top->next;
	top->next = bottom;
	bottom->prev = top;
	*stack = bottom->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
