#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int character;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	character = (*stack)->n;
	if (character < 0 || character > 127)
		string_err(10, line_number);
	printf("%c\n", character);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int character;
	stack_t *current_node;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	current_node = *stack;
	while (current_node != NULL)
	{
		character = current_node->n;
		if (character <= 0 || character > 127)
			break;
		printf("%c", character);
		current_node = current_node->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current_node = *stack;
	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	(*stack)->prev = current_node;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *current_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	current_node = *stack;

	while (current_node->next != NULL)
		current_node = current_node->next;

	current_node->next = *stack;
	current_node->prev->next = NULL;
	current_node->prev = NULL;
	(*stack)->prev = current_node;
	(*stack) = current_node;
}
