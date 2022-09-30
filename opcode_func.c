#include "monty.h"

/**
 * f_push - Function that pushes a number to a stack
 * @stack: Address of Head of Stack
 * @num: Line count
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

/**
 * f_pint - prints the value at top of the stack
 * @stack: Address of Head of Stack
 * @num: Line Count
 *
 * Return: void
 */

void f_pint(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", num);
		free_stack(*stack);
		fclose(fil);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", head->n);
}

/**
 * f_pop - removes the top element of the stack.
 * @stack: Address of Head of Stack
 * @num: Lone count
 *
 * Return: void
 */

void f_pop(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", num);
		fclose(fil);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (!head->next)
	{
		*stack = NULL;
	}
	else
	{
		*stack = head->next;
		head->next->prev = head->prev;
	}
	free(head);	
}
