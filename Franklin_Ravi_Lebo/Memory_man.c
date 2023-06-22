#include "monty.h"

/**
 * empty_stack - function to free stack on exit
 *
 * @stack: the pointer stack
 *
 * Return: Nothing
 */
void empty_stack(stack_t *stack)
{
	stack_t *temp = NULL, *ptr = stack;

	while (ptr != NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		free(temp);
	}
}
