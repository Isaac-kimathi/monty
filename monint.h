#ifndef MONINT_H
#define MONINT_H

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void opcode(stack_t **stack, char *substance, unsigned int idx);
void pushx(stack_t **stack, unsigned int idx);
void nd_add(stack_t **head, int n);
void pall_s(stack_t **head, unsigned int idx);
void queue_add(stack_t **head, int n);
void free_dlnk_lst(stack_t *head);
ssize_t x_gtline(char **nm, size_t *n, FILE *fd);
void op_pint(stack_t **stack, unsigned int idx);

#endif
