#include "monty.h"

/**
 * mont_swap - swaps the top two elements of the stack.
 * @stack: Stack
 * @line_number: Number of the line
 */
void mont_swap(stack_t **stack, unsigned int line_number)
{
	int iTemp = 0;

	if ((*stack)->next == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	iTemp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = iTemp;
}


/**
 * mont_add - add the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void mont_add(stack_t **stack, unsigned int line_number)
{
	int iTotal = 0;
	stack_t *node_iterator = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_iterator = *stack;
	iTotal = node_iterator->n + node_iterator->next->n;
	node_iterator->next->n = iTotal;
	mont_pop(stack, line_number);
}

/**
 * mont_nop - function void
 * @stack: Stack list
 * @line_number: Number of the line
 */
void mont_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
