#include "monty.h"
/**
 * pchar - prints the ascii value of the top
 * @top: top of the stack
 * @n: the value on the top
 */
void pchar(stack_t **top, __attribute__((unused))unsigned int n)
{
	char character = 'a';

	character = (*top)->n;

	printf("%c\n", character);
}