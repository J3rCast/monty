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
	if (arg == NULL || isInteger(arg) == 1)
	{
		free_dlistint(*top);
		fprintf(stderr, "L%d: usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	else
		argNum = _atoi(arg);

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
/**
 * pint - print the top of the stack
 * @top: top of the stack
 * @n: the value on the top
 */
void pint(stack_t **top, __attribute__((unused))unsigned int n)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*top)->n);
}
/**
 * pint - print the top of the stack
 * @top: top of the stack
 * @n: the value on the top
 */
void pop(stack_t **top, __attribute__((unused))unsigned int n)
{
	stack_t *temp = NULL;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", lineNum);
		exit(EXIT_FAILURE);
	}
	temp = (*top);

	*top = (*top)->next;

	free(temp);
}
