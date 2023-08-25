#include "monty.h"
/**
 * f_queue - this function prints the top
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - this function adds a node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: void
*/
void addqueue(stack_t **head, int n)
{
	stack_t *nn, *a;

	a = *head;
	nn = malloc(sizeof(stack_t));
	if (nn == NULL)
	{
		printf("Error\n");
	}
	nn->n = n;
	nn->next = NULL;
	if (a)
	{
		while (a->next)
			a = a->next;
	}
	if (!a)
	{
		*head = nn;
		nn->prev = NULL;
	}
	else
	{
		a->next = nn;
		nn->prev = a;
	}
}

