#include "monty.h"
/**
 * f_swap -this Fuction adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_swap(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int L = 0, A;

	h = *head;
	while (h)
	{
		h = h->next;
		L++;
	}
	if (L < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	A = h->n;
	h->n = h->next->n;
	h->next->n = A;
}
