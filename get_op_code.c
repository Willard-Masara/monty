#include "monty.h"
#include <stdio.h>

void (*get_opcode_function(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{NULL, NULL}
	};

	int i = 0;
	while (opcodes[i].opcode)
	{
	if (strcmp(opcode, opcodes[i].opcode) == 0)
	    return (opcodes[i].f);
	i++;
	}
	return (NULL);
}
