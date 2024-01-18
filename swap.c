#include "monty.h"

/**
 * f_swap - Swaps the top two elements of the stack.
 * @head: Pointer to the stack's head
 * @counter: Line number
 * Return: No return value
 */
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *code;
	int len = 0, dan;

	code = *head;
	while (code)
	{
		code = code->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	code = *head;
	dan = code->n;
	code->n = code->next->n;
	code->next->n = dan;
}
