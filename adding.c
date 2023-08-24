#include "monty.h"
/**
 * f_add - adds the first two elements of the stack.
 * @head: the head of the stack
 * @counter: counts the number lines
 * Return: no return
*/
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int line_counter = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		line_counter++;
	}
	if (line_counter < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

