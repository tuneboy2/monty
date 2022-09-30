#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second top element of the
 * stack by the top element of the stack.
 * @stack: Address of the Head Stack
 * @num: Line count
 *
 * Return: void
 */

void f_mod(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack;
	int no = 0;

	while (head && no < 2)
	{
		no++;
		head = head->next;
	}

	head = *stack;
	if (no < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", num);
		fclose(fil);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(fil);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	head->next->n = head->next->n % head->n;
	*stack = head->next;
	free(head);
}