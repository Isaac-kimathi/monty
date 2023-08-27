#include <stdio.h>
#include <stdlib.h>
#include "monint.h"

int cndt = 0;

/**
 * main - monty code interpreter
 * @argc: argument number
 * @argv: file location of monty file
 * Return: nothing
 */
int main(int argc, char *argv[])
{
	char *substance = NULL, *bptr = NULL;
	FILE *file;
	unsigned int idx = 1;
	stack_t *stack = NULL;
	size_t sz = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while ((x_gtline(&bptr, &sz, file)) != (-1))
	{
		if (cndt)
			break;
		if (*bptr == '\n')
		{
			idx++;
			continue;
		}
		substance = strtok(bptr, " \t\n");
		if (!substance || *substance == '#')
		{
			idx++;
			continue;
		}
		opcode(&stack, substance, idx);
		idx++;
	}

	free(bptr);
	free_dlnk_lst(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}
