#include "monty.h"

/**
 * free_stack - A function  that frees a dlistint_t
 * @head: A pointer to the list
 *
 * Return: Void
 */

void free_stack(stack_t *head)
{
	stack_t *temp;
	stack_t *current = head;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
