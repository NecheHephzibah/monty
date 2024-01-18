#include "monty.h"


/**
  * _addStack - function to add new nodes to stack pile.
  * @head: pointer to pointer of the beginning of the stack.
  * @num: integer input by user.
  * Return: void
  */

void _addStack(stack_t **head, int num)
{
	stack_t *new_node;

	new_node =  malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	if (*head != NULL)
		(*head)->prev = new_node;
	*head = new_node;
}
