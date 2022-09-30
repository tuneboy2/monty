#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define BUFSIZE 100

FILE *fil;
char *value;
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


char *_realloc(char *, int);
stack_t *add_node(stack_t **head, int n);
void execute(stack_t **, FILE *, char *, int);
void free_stack(stack_t *);

/* opcodes */
void f_push(stack_t **, unsigned int);
void f_pall(stack_t **, unsigned int);
void f_pint(stack_t **, unsigned int);
void f_pop(stack_t **, unsigned int);
void f_swap(stack_t **, unsigned int);

#endif
