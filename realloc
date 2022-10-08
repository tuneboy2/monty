#include "monty.h"

/**
 * _realloc - Reallocate Memory
 * @size: Current size
 * @ptr: Pointer to element to be realloced
 *
 * Return: void
 */

char *_realloc(char *ptr, int size)
{
	char *buf = ptr;

	size += BUFSIZE;
	ptr = malloc(size * sizeof(char));
	if (!ptr)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(ptr);
		exit(EXIT_FAILURE);
	}

	strcpy(ptr, buf);
	free(buf);

	return (ptr);
}
