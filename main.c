#include <stdio.h>
#include <stdlib.h>
#include "monint.h"

/**
 * main - monty code interpreter
 * @argc: argument number
 * @argv: file location of monty file
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
	char *substance = NULL;
	FILE *file;
	unsigned int idx = 0;
	stack_t *stack = NULL;
	size_t sz = 0, ln_rd = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (ln_rd > 0)
	{
		ln_rd = x_gtline(&substance, &sz, file);
		substance++;
		if (ln_rd > 0)
		{
			x_excut(substance, &stack, idx, file);
		}
		free(substance);
	}
	free_dlnk_lst(stack);
	fclose(file);

	return(0);
}
