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
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	if (head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	head->next->n = head->next->n % head->n;
	*stack = head->next;
	free(head);
}

/**
 * f_pchar - prints the char at the top of the stack
 * @stack: Address of Head stack
 * @num: Line count
 *
 * Return: void
 */

void f_pchar(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack;
	int no;

	if (!head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	no = head->n;
	if (no < 0 ||  no > 127)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", no);
}

/**
 * f_pstr - prints the string starting at the top of the stack.
 * @stack: Address of Head Stack
 * @num: line countet
 *
 * Return: void
 */

void f_pstr(stack_t **stack, __attribute__((unused))unsigned int num)
{
	stack_t *head = *stack;

	while (head)
	{
		if (head->n <= 0 || head->n > 127)
			break;

		putchar(head->n);
		head = head->next;
	}
	putchar(10);
}

/**
 * f_rotl - rotates the stack to the top.
 * @stack: Address of Head Nodr
 * @num: line count
 *
 * Return: void
 */

void f_rotl(stack_t **stack, __attribute__((unused))unsigned int num)
{
	stack_t *current, *head = *stack, *temp;

	if (!head)
		return;

	temp = head;
	head = head->next;
	if (head)
		head->prev = NULL;
	else
		return;

	current = head;
	while (current->next)
		current = current->next;

	temp->prev = current;
	current->next = temp;
	temp->next = NULL;

	*stack = head;
}


