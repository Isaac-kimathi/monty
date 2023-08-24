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
/**
 * struct fix_s - struct for variables - arg, file, substance
 * @av: value of argument
 * @file: pointer to monty file
 * @subs: content of line in file
 * @rt: flag change stack to queue and vice versa
 * Description: carrier of values throught the program
 */
typedef struct fix_s
{
	FILE *file;
	char *av;
	int rt;
	char *subs;
} fix_t;
extern fix_t fx;
int x_excut(char *substance, stack_t **stack, unsigned int idx, FILE *file);
void pushx(stack_t **head, unsigned int idx);
void nd_add(stack_t **head, int n);
void pall_s(stack_t **head, unsigned int idx);
void queue_add(stack_t **head, int n);
void free_dlnk_lst(stack_t *head);

#endif
