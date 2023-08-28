#include "monint.h"

/**
 * op_ pchar - prints the int at the top of the stack as char
 * @stack: main function stack
 * @idx: number of lines
 *
 * Return: void
 */
void op_pchar(stack_t **stack, unsigned int idx)
{
	int zx;

	if (!(stack || (*stack)))
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", idx);
		exit(EXIT_FAILURE);
		return;
	}
        zx = (*stack)->n;
	if (zx < 0 || zx > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", idx);
		exit(EXIT_FAILURE);
		return;
	}
	printf("%c\n", (*stack)->n);
}
