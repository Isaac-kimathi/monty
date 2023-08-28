#include "monint.h"

/**
 * op_pstr - prints the contents of a stack_t stack as a string
 * @stack: main function stack
 * @idx: number of lines in the file
 *
 * Return: void
 */
void op_pstr(stack_t **stack, unsigned int idx)
{
	stack_t *present = *stack;
	(void)idx;
	
	while (present)
	{
		if (present->n <= 0 || present->n > 127)
			break;
		putchar((char) present->n);
		present = present->next;
	}
	putchar('\n');
}
