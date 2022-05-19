#include "monty.h"
/**
 * push - push to the stack
 * @top: top of the stack
 * @n: the value of the new node added to the stack
 */
void push(stack_t **top, unsigned int n)
{
	char *arg = NULL;
	unsigned int argNum = 0;
	stack_t *newNode = NULL;

	arg = strtok(NULL, " \n\t");
	if (isInteger(arg) == 0 && arg != NULL)
		argNum = _atoi(arg);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}

	newNode = getNewNode(argNum);

	if (!*top)
	{
		*top = newNode;
		return;
	}

	(*top)->prev = newNode;
	newNode->next = *top;
	*top = newNode;
}
/**
 * pall - print all elements of a stack
 * @top: top of the stack
 * @n: the value on the top
 */
void pall(stack_t **top, __attribute__((unused))unsigned int n)
{
	stack_t *temp;

	temp = *top;

	if (*top == NULL)
		return;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
