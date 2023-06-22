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

void close_and_free(glo_t *global, stack_t *stack)
{
	free(global->get_line);
	empty_stack(stack);
	fclose(global->file_d);
}

void file_err(char *argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv);
	exit(EXIT_FAILURE);
}

void res_chck(char *itm, int cnt, glo_t *gb, char *ars, stack_t **stk, int res)
{
	res = opc_fun(stk, ars, itm, cnt);
	if (res == 1)
		push_err(gb->file_d, gb->get_line, *stk, cnt);
	else if (res == 2)
		no_cmd(gb->file_d, gb->get_line, *stk, ars, cnt);
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
	char *args = NULL, *item = NULL;
	stack_t *stack = NULL;

	global.file_d = fopen(argv, "r");
	if (global.file_d)
	{
		for (; getline(&global.get_line, &bufsize, global.file_d) != -1;)
		{
			count++;
			args = strtok(global.get_line, " \n\t\r");
			if (args == NULL)
			{
				free(args);
				continue;
			}
			else if (*args == '#' || *args == '-')
				continue;
			item = strtok(NULL, " \n\t\r");
			res_chck(item, count, &global, args, &stack, result);
		}
		close_and_free(&global, stack);
	}
	else
		file_err(argv);
}
