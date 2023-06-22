#include "monty.h"

int value;

/**
 * mont_push - inserts a node to a top of stack
 *
 * @stack: head of stack
 * @line_number: current line number
 * Return: void
 */
void mont_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_item = NewElement(value);

	if (*stack != NULL)
		(*stack)->prev = new_item;

	new_item->next = *stack;
	*stack = new_item;

	(void)line_number;
}

/**
 * mont_pall - prints all element in a stack
 *
 * @stack: head of stack
 * @line_number: the value
 *
 * Return: Nothing
 */
void mont_pall(stack_t **stack, unsigned int line_number)
{
	/*stack_t *node_iterator = (stack_t *)malloc(sizeof(stack_t));*/
	stack_t *node_iterator = *stack;

	(void)line_number;
	if (!node_iterator)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	node_iterator = *stack;
	for (; node_iterator != NULL; node_iterator = node_iterator->next)
	{
		dprintf(STDOUT_FILENO, "%d\n", node_iterator->n);
	}
}

/**
 * mont_pint - prints the value at the top of the stack,
 * followed by a new line.
 *
 * @stack: stack
 * @line_number: current line number
 *
 * Return: Nothing
 */

void mont_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack && stack)
	{
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * mont_pop - removes the top element of the stack.
 *
 * @stack: stack
 * @line_number: current line number
 *
 * Return: Nothing
 */

void mont_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_item;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_item = *stack;
	*stack = top_item->next;
	if (top_item->next != NULL)
		top_item->prev = NULL;
	free(top_item);
}
