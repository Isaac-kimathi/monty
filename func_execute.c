#include "monint.h"
/**
 * execute - executes the opcode
 * @stack: head to double linked list of stack
 * @idx: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: void
 */
void x_excut(char *substance, stack_t **stack, unsigned int idx, FILE *file)
{
	instruction_t funcopt[] = {
		{"push", pushx},
		{"pall", pall_s},
		{"pint", op_pint},
		{NULL, NULL}
	};

	unsigned int x = 0;
	char *opc;

	opc = strtok(substance, " \t\n");
	if (opc && opc[0] == '#') { 
		; }
	for (; funcopt[x].opcode && opc; x++)
	{
		if(strcmp(opc, funcopt[x].opcode) == 0)
			funcopt[x].f(stack, idx);
	}
	if (opc && funcopt[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", idx, opc);
		fclose(file);
		free(substance);
		exit(EXIT_FAILURE);
	}
}
