#include "monint.h"
/**
 * pushx_add node to a stack
 * @head: head of a stack
 * idx: the number of a line
 * Return: void
 */
void pushx(stack_t **head, unsigned int idx)
{
	char *xp = NULL, *sb = NULL;
	FILE *fl = NULL; 
	int ty = 0,  x, k = 0, flg = 0;
	
	if (xp)
	{
		if (xp[0] == '-')
			k++;
		for (; xp[k] != '\0'; k++)
		{
			if (xp[k] > 57 || xp[k] < 48)
				flg = 1;
		}
		if (flg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", idx);
			fclose(fl);
			free(sb);
			free_dlnk_lst(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", idx);
		fclose(fl);
		free(sb);
		free_dlnk_lst(*head);
		exit(EXIT_FAILURE);
	}
	x = atoi(xp);
	if (ty == 0)
		nd_add(head, x);
	else
		queue_add(head, x);
}
