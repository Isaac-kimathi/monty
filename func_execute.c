#include "monint.h"
/**
 * execute - executes the opcode
 * @stack: head to double linked list of stack
 * @idx: line_counter
 * @file: pointer to monty file
 * @content: line content
 * Return: void
 */
int x_excut(char *substance, stack_t **stack, unsigned int idx, FILE *file)
{
	instruction_t funcopt[] = {
		{"push", pushx},
		{"pall", pall_s},
		{NULL, NULL}
	};

	unsigned int x = 0;
	char *opc;

	opc = strtok(substance, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	while (funcopt[x].opcode && opc)
	{
		if (strcmp(opc, funcopt[x].opcode) == 0)
		{
			funcopt[x].f(stack, idx);
			return (0);
		}
		x++;
	}
	if (opc && funcopt[x].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", idx, opc);
		fclose(file);
		free(substance);
		free_dlnk_lst(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
