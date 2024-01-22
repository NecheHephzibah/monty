#include "monty.h"

cmdline_t cmd_args;

/**
  * _pop - function to removes the node at the top of the stack and frees it.
  * @stack: pointer to the pointer of the head of a node/list.
  * @line_number: counter stored.
  * Return: void
  */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *node_to_remove;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(cmd_args.file);
		free(cmd_args.contents);
		free_stack(stack);

		exit(EXIT_FAILURE);
	}

	node_to_remove = *stack;

	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}

	free(node_to_remove);
}
