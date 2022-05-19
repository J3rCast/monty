#include "monty.h"
/**
 * add - add bewtween top
 * @top: top of the stack
 * @n: the value on the top
 */
void add(stack_t **top, __attribute__((unused))unsigned int n)
{
	int temp = 0;

	if (!(*top) || !(*top)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", lineNum);
		exit(EXIT_FAILURE);
	}

	temp = (*top)->n;
	(*top)->next->n = (*top)->next->n + temp;
	pop(top, lineNum);
}
