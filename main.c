#include "monty.h"
#include <stdio.h>

int main(int argc, char *argv[])
{

	FILE *file;
	stack_t *stack;
	unsigned int line_number;
	char *opcode;
	char line[1024];

	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	return (EXIT_FAILURE);
	}

	stack = NULL;
	line_number = 1;

	while (fgets(line, sizeof(line), file))
	{
	opcode = strtok(line, " \t\n");
	if (opcode)
	{
	void (*opcode_function)(stack_t **, unsigned int) = get_opcode_function(opcode);
	if (opcode_function)
	opcode_function(&stack, line_number);
	else
	{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	fclose(file);
	free_stack(&stack);
	return (EXIT_FAILURE);
	}
	}
	line_number++;
	}

	fclose(file);
	free_stack(&stack);

	return (EXIT_SUCCESS);
}
