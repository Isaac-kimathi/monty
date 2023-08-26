#include "monint.h"

/**
 * x_gtline - reads lines from monty file.
 * nm: double pointer holding the address of the buffer containing the rd_ln;
 * x: pointer to a size_t var that store the size of the allocated buffer
 * fd: a File pointer representing the input stream
 * Return: signed int
 */
ssize_t x_gtline(char **nm, size_t *x, FILE *fd)
{
	char *fx = NULL;
	size_t xp = 0;
	int sd;

	if(nm == NULL || x == NULL || fd == NULL)
		return -1;
	if (*nm == NULL || *x == 0)
	{
		*x = 128;
		*nm = (char *)malloc(*x);
		if (*nm == NULL)
		{
			return -1;
		}
	}
	while ((sd = fgetc(fd)) != EOF)
	{
		if (xp + 1 >= *x)
		{
			size_t nw_sz = *x * 2;
			fx = (char *)realloc(*nm, nw_sz);
			if (fx == NULL)
			{
				return -1;
			}
			*nm = fx;
			*x = nw_sz;
		}
		(*nm)[xp++] = sd;
		if (sd == '\n')
		{
			break;
		}
	}
	if (xp == 0)
	{
		return -1;
	}
	(*nm)[xp] = '\0';
	return xp;
}
