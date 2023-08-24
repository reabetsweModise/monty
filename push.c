#include "monty.h"
/**
 * f_push - this function adds a node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: void
*/
void f_push(stack_t **head, unsigned int counter)
{
	int M, K = 0, F = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			K++;
		for (; bus.arg[K] != '\0'; K++)
		{
			if (bus.arg[K] > 57 || bus.arg[K] < 48)
				F = 1;
		}
		if (F == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	M = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, M);
	else
		addqueue(head, M);
}
