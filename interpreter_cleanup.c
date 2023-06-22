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
	stack_t *itr_pointer = NULL;

	itr_pointer = stack;

	if (!itr_pointer)
	{
		empty_stack(itr_pointer->next);
		free(itr_pointer);
	}
}
