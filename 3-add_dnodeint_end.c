#include "monty.h"

/**
 * add_node_end - A function  that adds a new node at the end of a list
 * @head: Address of the Head Node
 * @n: Dat value to be inserted
 *
 * Return: Address of the New element or NULL
 */

stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new;
	stack_t *current = *head;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = *head;
		*head = new;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;

		current->next = new;
		new->prev = current;
	}

	return (*head);
}
