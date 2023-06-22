#include "monty.h"

glo_t global = {NULL, NULL};
/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: number of arguments.
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
		command_handler(argv[1]);
	else
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
/**
 * command_handler - Read file
 * @argv: Arguments
 * Return: Nothing
 */
void command_handler(char *argv)
{
	int count = 0, result = 0;
	size_t bufsize = 0;
	char *arguments = NULL, *item = NULL;
	stack_t *stack = NULL;

	global.file_d = fopen(argv, "r");
	if (global.file_d)
	{
		while (getline(&global.get_line, &bufsize, global.file_d) != -1)
		{
			count++;
			arguments = strtok(global.get_line, " \n\t\r");
			if (arguments == NULL)
			{
				free(arguments);
				continue;
			}
			else if (*arguments == '#' || *arguments == '-')
				continue;
			item = strtok(NULL, " \n\t\r");
			result = opc_fun(&stack, arguments, item, count);
			if (result == 1)
				push_err(global.file_d, global.get_line, stack, count);
			else if (result == 2)
				no_cmd(global.file_d, global.get_line, stack, arguments, count);
		}
		free(global.get_line);
		empty_stack(stack);
		fclose(global.file_d);
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv);
		exit(EXIT_FAILURE);
	}
}
