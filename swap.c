#include "monty.h"

/**
 * swap_top_two - function that swaps the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @line_number: Line number
 * Return: No return value
 */
void swap_top_two(stack_t **head, unsigned int line_number)
{
	stack_t *first_node;
	int temp_value;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(cmd_args.file);
		free(cmd_args.contents);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	first_node = *head;
	temp_value = first_node->n;
	first_node->n = first_node->next->n;
	first_node->next->n = temp_value;
}
