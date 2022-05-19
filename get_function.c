#include "monty.h"
/**
 * get_function - get the correct function based on script.
 * @script: script passed by getting every line of a file
 * and parse.
 *
 * Return: the correct function
 */
void (*get_function(char *script))(stack_t **top, unsigned int arg)
{
	int i = 0;

	instruction_t obtain[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (obtain[i].opcode != NULL)
	{
		if (strcmp(script, obtain[i].opcode) == 0)
			break;
		i++;
	}
	if (obtain[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", lineNum, script);
		exit(EXIT_FAILURE);
	}

	return (obtain[i].f);
}
