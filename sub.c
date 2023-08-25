#include "monty.h"
/**
  *f_sub- this function sustration
  *@head: stack head
  *@counter: line_number
  *Return: void
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux;
	int s, nod;

	aux = *head;
	for (nod = 0; aux != NULL; nod++)
		aux = aux->next;
	if (nod < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	s = aux->next->n - aux->n;
	aux->next->n = s;
	*head = aux->next;
	free(aux);
}
