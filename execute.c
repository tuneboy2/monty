#include "monty.h"

/**
 * execute - Parse and Run Commands
 * @stack: Address of Head Node
 * @content: Line containing Opcode
 * @counter: Line Counter
 *
 * Return: void
 */

void execute(stack_t **stack, char *content,  int counter)
{
	int i = 0;
	char *op;
	instruction_t opst[] = {
			{"push", f_push}, {"pall", f_pall}, {"pint", f_pint}, {"pop", f_pop},
			{"swap", f_swap},
			{"add", f_add},
			{"nop", f_nop},
			{"sub", f_sub},
			{"mul", f_mul},
			{"mod", f_mod},
			{"div", f_div},
			{"pchar", f_pchar},
			{"pstr", f_pstr},
			{"rotl", f_rotl},
			{NULL, NULL}
			};

	op = strtok(content, " \t\n");
	if (op && op[i] == '#')
		return;

	value = strtok(NULL, " \t\n");

	while (op && opst[i].opcode)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return;
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(ptr);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
}
