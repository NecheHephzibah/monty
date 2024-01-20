#include "monty.h"

/**
  * _add - function to removes the node at the top of the stack and frees it.
  * @stack: pointer to the pointer of the head of a node/list.
  * @line_number: counter stored.
  * Return: void
  */

void _add(stack_t **stack, unsigned int line_number)
{
	int sum;
	stack_t *node_to_remove;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		fclose(cmd_args.file);
		free(cmd_args.contents);
		free_stack(stack);

		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;

	node_to_remove = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(node_to_remove);

	(*stack)->n = sum;
}
