 #include "monty.h"

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
		fclose(ptr);
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

/**
 * f_nop - Does nothing
 * @stack: Address of stack pointer
 * @num: line count
 *
 * Return: void
 */

void f_nop(__attribute__((unused))stack_t **stack, __attribute__((unused))unsigned int num)
{
	return;
}

/**
 * f_sub - subtracts the top element of the stack from the second top element
 * of the stack
 * @stack: Address of Head of the Stack
 * @num: Line count
 *
 * Return: void
 */

void f_sub(stack_t **stack, unsigned int num)
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
		fprintf(stderr, "L%d: can't sub, stack too short\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		head->next->n = head->next->n - head->n;
		*stack = head->next;
		free(head);
	}
}

/**
 * f_div - divides the second top element of the stack by the top element of
 * the stack.
 * @stack: Address of the Head Stack
 * @num: Line count
 *
 * Return: void
 */

void f_div(stack_t **stack, unsigned int num)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (head->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", num);
			fclose(ptr);
			free_stack(*stack);
			exit(EXIT_FAILURE);
		}

		head->next->n = head->next->n / head->n;
		*stack = head->next;
		free(head);
	}
}

/**
 * f_mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @stack: Address of the Head stack
 * @num: Line count
 *
 * Return: void
 */

void f_mul(stack_t **stack, unsigned int num)
{
	stack_t *head = *stack;
	int no = 0, mul = 1;

	while (head && no < 2)
	{
		no++;
		mul *= head->n;
		head = head->next;
	}

	head = *stack;
	if (no < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", num);
		fclose(ptr);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	head->next->n = mul;
	*stack = head->next;
	free(head);
}
