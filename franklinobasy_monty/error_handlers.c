#include "monty.h"

/**
 * push_failure - handle push error
 *
 * @fd: is a file desciptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 *
 * Return: void
 */
void push_failure(FILE *fd, char *line, stack_t *stack, int count)
{
	fprintf(stderr, "L%u: usage: push integer\n", count);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * no_command - Error handler
 * @fd: is a file descriptor
 * @line: is a buffer
 * @stack: is a stack or queue
 * @count: is a line command
 * @arg: command entered
 */
void no_command(FILE *fd, char *line, stack_t *stack, char *arg, int count)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", count, arg);
	fclose(fd);
	free(line);
	free_stack(stack);
	exit(EXIT_FAILURE);
}
