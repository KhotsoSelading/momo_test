#include "monty.h"

glob_t global = {NULL, NULL};
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 * Return: number of arguments.
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		handle_command(argv[1]);
	else
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * handle_command - Read file
 * @argv: Arguments
 * Return: Nothing
 */
void handle_command(char *argv)
{
	int count = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *item = NULL;
	stack_t *stack = NULL;

	global.fd = fopen(argv, "r");
	if (global.fd)
	{
		while (getline(&global.line, &bufsize, global.fd) != -1)
		{
			count++;
			arguments = strtok(global.line, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			else if (*arguments == '#' || *arguments == '-')
				continue;
			item = strtok(NULL, " \n\t\r");
			result = get_opc(&stack, arguments, item, count);
			if (result == 1)
				push_failure(global.fd, global.line, stack, count);
			else if (result == 2)
				no_command(global.fd, global.line, stack, arguments, count);
		}
		free(global.line);
		free_stack(stack);
		fclose(global.fd);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}