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
	FILE *file;
	unsigned int idx = 0;
	stack_t *stack = NULL;
	size_t sub_sz = 1024;
	char *substance = (char *)malloc(sub_sz);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	if (!substance)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		fclose(file);
		return EXIT_FAILURE;
	}

	while (fgets(substance, sub_sz, file) != NULL)
	{
		x_excut(substance, &stack, idx, file);
		free(substance);
	}
	free_dlnk_lst(stack);
	fclose(file);

	return(0);
}
