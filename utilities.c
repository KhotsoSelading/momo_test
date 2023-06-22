#include "monty.h"

/**
 * NewElement - Create a new node for the stack
 *
 * @value: value to be assigned to the node
 *
 * Return: new node created
 */

stack_t *NewElement(int value)
{
	stack_t *new_node = NULL;

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc operation failed :(.\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * isClear - checks if stack empty
 *
 * @stack: the stack to be validated
 *
 * Return: 1 if true else 0
 */

int isClear(stack_t **stack)
{
	return ((*stack == NULL) ? 1 : 0);
}

/**
 * num_validator - Checks for a digit 0 through 9
 * Return: 0 or 1
 * @c: Variable
 **/
int num_validator(char *c)
{
	int hasDigits = 0, isNegative = 0;

	if (c == NULL || *c == '\0')
		return (0);

	isNegative = (*c == '-');

	if (isNegative)
		c++;

	while (*c != '\0')
	{
		if (*c >= '0' && *c <= '9')
			hasDigits = 1;
		else
			return (0);
		c++;
	}

	return (hasDigits ? 1 : 0);
}

