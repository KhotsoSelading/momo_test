#include "monty.h"

/**
 * get_opc - function to handle the opcodes
 * @stack: is a stack or queue
 * @arg: command to compare with available opcodes
 * @item: value to push
 * @count: line number
 *
 * Return: void
 */
int get_opc(stack_t **stack, char *arg, char *item, int count)
{
	size_t idx = 0;

	instruction_t opcodes[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	while (opcodes[idx].opcode)
	{
		if (!strcmp(arg, opcodes[idx].opcode))
		{
			if (!strcmp(arg, "push"))
			{
				if (isvalid_digit(item) == 1)
					value = atoi(item);
				else
					return (1);
			}
			opcodes[idx].f(stack, (unsigned int)count);
			break;
		}
		idx++;
	}
	if (!opcodes[idx].opcode)
		return (2);

	return (0);
}
