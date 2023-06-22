#include "monty.h"

/**
 * mont_sub - sub the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void mont_sub(stack_t **stack, unsigned int line_number)
{
	int iTotal = 0;
	stack_t *node_iterator = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_iterator = *stack;
	iTotal = node_iterator->next->n - node_iterator->n;
	node_iterator->next->n = iTotal;
	mont_pop(stack, line_number);
}

/**
 * mont_div - div the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void mont_div(stack_t **stack, unsigned int line_number)
{
	int iTotal = 0;
	stack_t *node_iterator = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_iterator = *stack;
	iTotal = node_iterator->next->n / node_iterator->n;
	node_iterator->next->n = iTotal;
	mont_pop(stack, line_number);
}

/**
 * mont_mul - sub the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void mont_mul(stack_t **stack, unsigned int line_number)
{
	int iTotal = 0;
	stack_t *node_iterator = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_iterator = *stack;
	iTotal = node_iterator->next->n * node_iterator->n;
	node_iterator->next->n = iTotal;
	mont_pop(stack, line_number);
}

/**
 * mont_mod - sub the top two elements of the stack
 * @stack: double pointer tot he beginning of the stack
 * @line_number: script line number
 *
 * Return: void
 */
void mont_mod(stack_t **stack, unsigned int line_number)
{
	int iTotal = 0;
	stack_t *node_iterator = NULL;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node_iterator = *stack;
	iTotal = node_iterator->next->n % node_iterator->n;
	node_iterator->next->n = iTotal;
	mont_pop(stack, line_number);
}


