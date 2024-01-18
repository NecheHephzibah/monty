#include "monty.h"

/**
  * _pall - function that prints all the elements(nodes)
  * in a stack or queue.
  * @head: the beginning of the list (stack /queue)
  * @line_number: counters the number of integers stored.
  * Return: void/nothing.
  */


void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *current_node;

	(void)line_number;

	if (*head == NULL)
		return;

	current_node = *head;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
