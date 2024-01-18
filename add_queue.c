#include "monty.h"

/**
  * _addQueue - function to add new nodes to the bottom of stack.
  * @head: pointer to pointer of the beginning of the stack.
  * @num: integer input by user.
  * Return: void
  */


void _addQueue(stack_t **head, int num)
{
	stack_t *new_node, *temp;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->next = NULL;

	if(*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = new_node;
		new_node->prev = temp;
	}
}
