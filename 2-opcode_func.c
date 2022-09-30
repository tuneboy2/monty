 #include "monty.h"

/**
 * f_nop - The opcode nop doesn’t do anything
 *
 * Return: void
 */

void f_nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int num)
{
	return;
}

/**
 * f_add - adds the top two elements of the stack.
 * @stack: Address of the Head Stack
 * @num: Line count
 *
 * Return: void
 */

void f_add(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack;
	int no = 0, sum = 0;
	
	while (head && no < 2)
	{
		no++;
		sum += head->n;
		head = head->next;
	}

	head = *stack;
	if (no < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", num);
		fclose(fil);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		head->next->n = sum;
		*stack = head->next;
		free(head);
	}
}

