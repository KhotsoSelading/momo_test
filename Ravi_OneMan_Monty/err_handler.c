#include "monty.h"

/**
 * push_err - handle the push error
 *
 * @file_d: file desciptor
 * @get_line: a buffer
 * @stack: a stack or queue
 * @cnt: a line command
 *
 * Return: Nothing
 */
void push_err(FILE *file_d, char *get_line, stack_t *stack, int cnt)
{
	fprintf(stderr, "L%u: usage: push integer\n", cnt);
	fclose(file_d);
	free(get_line);
	empty_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * no_cmd - An error handler
 * @file_d: file descriptor
 * @get_line: a buffer
 * @stack: a stack or queue
 * @cnt: a line command
 * @arg: the command entered
 */
void no_cmd(FILE *file_d, char *get_line, stack_t *stack, char *arg, int cnt)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", cnt, arg);
	fclose(file_d);
	free(get_line);
	empty_stack(stack);
	exit(EXIT_FAILURE);
}
