#include "monint.h"

/**
 * rotr - rotates the last node of a stack_t stack to the top of the stack
 * @stack: stack head
 * @idx: line count of file
 *
 * Return: void
 */
void rotr_op(stack_t **stack, unsigned int idx)
{
	stack_t *bottom;
	stack_t *top;

	(void) idx;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	top = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	top->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
