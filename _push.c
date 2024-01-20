#include "monty.h"

/**
  * _push - function that pushes a new element(node) to the top of
  * the stack.
  * @head: where the list begins.
  * @line_number: a counter, helps to add the total number of
  * nodes/elements
  * in the stack.
  * Return: void.
  */

void _push(stack_t **head, unsigned int line_number)
{
	int i = 0, neg = 0, num;

	if (cmd_args.args == NULL)
		return;

	if (cmd_args.args[0] == '-')
		i++;
	while (cmd_args.args[i] != '\0' && (cmd_args.args[i] >= '0'
			&& cmd_args.args[i] <= '9'))
	{
		i++;
	}

	if (cmd_args.args[i] != '\0')
		neg = 1;

	if (neg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free(cmd_args.contents);
		fclose(cmd_args.file);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		num = atoi(cmd_args.args);
		if (cmd_args.num_conv == 0)
			_addStack(head, num);
		else
			_addQueue(head, num);
	}
}
