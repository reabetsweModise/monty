#include "monty.h"
/**
 * f_mod - calculates the division of the second
 * element of the stack
 * @head: head of the stack
 * @counter: number of lines
*/
void f_mod(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}

