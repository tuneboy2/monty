#include "monty.h"

/**
 * main - The Initialization function
 * @ac: Argument Count
 * @av: Argument Vector
 *
 * Return: 0 - SUCCESS
 */

int main(int ac, char **av)
{
	char *content = NULL;
	size_t len;
	ssize_t read_line = 1;
	int counter = 0;
	stack_t *stack = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	ptr = fopen(av[1], "r");
	if (!ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		read_line = getline(&content, &len, ptr);
		counter++;
		if (read_line > 0)
		{
			execute(&stack, content, counter);
		}
	}

	free(content);
	fclose(ptr);
	free_stack(stack);
	return (0);
}
