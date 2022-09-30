#include "monty.h"

/**
 * add_node - A function that adds a new node at the beginning of a list.
 * @head: Pointer to the Head Address
 * @n: Value to be inserted in the new node
 *
 * Return: Address of New Head
 */

stack_t *add_node(stack_t **head, int n)
{
	stack_t *new;
	stack_t *h = *head;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Failed to Allocate Memory\n");
		return (NULL);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
		h->prev = new;

	*head = new;

	return (*head);
}
