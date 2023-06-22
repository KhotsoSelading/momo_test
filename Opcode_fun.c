#include "monty.h"

/**
 * opc_fun - function to handle the opcodes
 * @stack: is a stack or queue
 * @arg: command to compare with available opcodes
 * @item: value to push
 * @cnt: line number
 *
 * Return: void
 */
int opc_fun(stack_t **stack, char *arg, char *item, int cnt)
{
	size_t idx;

	instruction_t opcodes[] = {
		{"push", mont_push},
		{"pall", mont_pall},
		{"pint", mont_pint},
		{"pop", mont_pop},
		{"swap", mont_swap},
		{"add", mont_add},
		{"nop", mont_nop},
		{NULL, NULL}
	};

	value = 0;

	for (idx = 0; opcodes[idx].opcode != NULL; idx++)
	{
		if (strcmp(arg, opcodes[idx].opcode) == 0)
		{
			if (strcmp(arg, "push") == 0)
			{
				if (num_validator(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			opcodes[idx].f(stack, (unsigned int)cnt);
			break;
		}
	}

	if (opcodes[idx].opcode == NULL)
		return (2);

	return (0);
}
