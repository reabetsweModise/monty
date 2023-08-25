#include "monty.h"
stack_t *head = NULL;
/**
 * main -this Fuction entry point
 * @argc: Arguments count
 * @argv: List of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node -this Fuction creates a stack_node.
 * @n: nmber to go inside the stack_node.
 * Return: Upon sucess a pointer to the stack_node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *stack_node;

	stack_node = malloc(sizeof(stack_t));
	if (stack_node == NULL)
		err(4);
	stack_node->next = NULL;
	stack_node->prev = NULL;
	stack_node->n = n;
	return (stack_node);
}

/**
 * free_nodes -this Fuction Frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *previous_node;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		previous_node = head;
		head = head->next;
		free(previous_node);
	}
}


/**
 * add_to_queue -this Fuction adds a stack_node to the queue.
 * @new_node: pointer to the new stack_node.
 * @ln: Line number of the opcode.
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *previous_node;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	previous_node = head;
	while (previous_node->next != NULL)
		previous_node = previous_node->next;

	previous_node->next = *new_node;
	(*new_node)->prev = previous_node;

}
