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
	int i = 0;

	if (!value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", num);
		free_stack(*stack);
		fclose(ptr);
		exit(EXIT_FAILURE);
	}

	while (value[i] != '\0')
	{
		if ((value[i] >= '0' && value[i] <= '9') || value[i] == '-')
		{
			i++;
			continue;
		}
		fprintf(stderr, "L%d: usage: push integer\n", num);
		free_stack(*stack);
		fclose(ptr);
		exit(EXIT_FAILURE);
	}

	if (key_value == 0)
		add_node(stack, atoi(value));
	else
		add_node_end(stack, atoi(value));

}

/**
 * f_pall - print all values on the stack
 * @stack: Addrss of Head of Stack
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
		fclose(ptr);
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
		fclose(ptr);
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

/**
 * f_swap - swaps the top two elements of the stack.
 * @stack: Address of Head of Stack
 * @num: Line count
 *
 * Return: void
 */

void f_swap(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack, *temp;
	int no = 0;

	while (head)
	{
		no++;
		head = head->next;
	}

	if (no < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		head = *stack;
		temp = head->next;
		temp->prev = head->prev;
		head->next = temp->next;
		temp->next = head;
		head->prev = temp;
		*stack = temp;

		if (no != 2)
			temp->next->prev = head;
	}
}
