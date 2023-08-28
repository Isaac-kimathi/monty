#include "monint.h"
/**
 * execute - executes the opcode
 * @stack: head to double linked list of stack
 * @idx: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: void
 */
void opcode(stack_t **stack, char *substance, unsigned int idx)
{
	instruction_t funcopt[] = {
		{"push", pushx},
		{"pall", pall_s},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", x_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", sub_op},
		{"div", op_div},
		{"mul", _mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{"rotl", rotl_op},
		{"rotr", rotr_op },
		{"stack", stack_op},
		{NULL, NULL}
	};

	unsigned int x = 0;

	if (!strcmp(substance, "stack"))
		return;

	if (!strcmp(substance, "queue"))
		return;

	while (funcopt[x].opcode)
	{
		if(strcmp(funcopt[x].opcode, substance) == 0)
		{
			funcopt[x].f(stack, idx);
			return;
		}
		x++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", idx, substance);
	exit(EXIT_FAILURE);
}
