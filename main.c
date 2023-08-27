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
	for (; x_gtline(&substance, &sz, file) != -1; substance++)
	{
		if (substance[strlen(substance) - 1] == '\n')
		{
			substance[strlen(substance) - 1] = '\0';
		}
		x_excut(substance, &stack, idx, file);
	}

	free(substance);
	fclose(file);

	return(0);
}
