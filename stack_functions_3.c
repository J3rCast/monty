#include "monty.h"
/**
 * pchar - prints the ascii value of the top
 * @top: top of the stack
 * @n: the value on the top
 */
void pchar(stack_t **top, __attribute__((unused))unsigned int n)
{
	char character = 'a';

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", lineNum);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 256)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", lineNum);
		exit(EXIT_FAILURE);
	}
	character = (*top)->n;

	printf("%c\n", character);
}