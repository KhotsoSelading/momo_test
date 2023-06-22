#include "monty.h"

/**
 * free_stack - frees the stack on exit
 *
 * @stack: pointer to the stack
 *
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *current = NULL;

	current = stack;

	if (current != NULL)
	{
		free_stack(current->next);
		free(current);
	}
}
