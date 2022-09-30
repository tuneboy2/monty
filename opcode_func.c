#include "monty.h"

/**
 * f_push - Function that pushes a number to a stack
 * @stack: Address of Head of Stack
 * @num: Number to be pushed on the stack
 *
 * Return: void
 */

void f_push(stack_t **stack, unsigned int num)
{
	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		free_stack(*stack);
		fclose(fil);
		exit(EXIT_FAILURE);
	}

	add_node(stack, atoi(value));

}

/**
 * f_pall - print all values on the stack
 * @stack: Address of Head of Stack
 * @num: Line count
 *
 * Return: void
 */

void f_pall(stack_t **stack, __attribute__((unused))unsigned int num)
{
	stack_t *head = *stack;

	if (!head)
	{
		return;
	}

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
