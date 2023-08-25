#include "monty.h"
#include <stdio.h>


void push(stack_t **stack, unsigned int line_number)
{

	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \t\n");

	if (!arg)
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	value = atoi(arg);

arg = strtok(NULL, " \t\n");arg = strtok(NULL, " \t\n");	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
	(*stack)->prev = new_node;

	*stack = new_node;
}
