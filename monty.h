#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


FILE *ptr;
int key_value;
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


stack_t *add_node(stack_t **head, int n);
void execute(stack_t **, char *, int);
void free_stack(stack_t *);
stack_t *add_node_end(stack_t **, int);

/* opcodes */
void f_push(stack_t **, unsigned int);
void f_pall(stack_t **, unsigned int);
void f_pint(stack_t **, unsigned int);
void f_pop(stack_t **, unsigned int);
void f_swap(stack_t **, unsigned int);
void f_nop(stack_t **, unsigned int);
void f_add(stack_t **, unsigned int);
void f_sub(stack_t **, unsigned int);
void f_div(stack_t **, unsigned int);
void f_mul(stack_t **, unsigned int);
void f_mod(stack_t **, unsigned int);
void f_pchar(stack_t **, unsigned int);
void f_pstr(stack_t **, unsigned int);
void f_rotl(stack_t **, unsigned int);

#endif
