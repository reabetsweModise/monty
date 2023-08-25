#include "monty.h"

/**
 * nop -this Fuction Does nothing.
 * @stack: pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes -this Fcution Swaps the top two elements of the stack.
 * @stack:pointing to top node of the stack.
 * @line_number: the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *previous_node;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	previous_node = (*stack)->next;
	(*stack)->next = previous_node->next;
	if (previous_node->next != NULL)
		previous_node->next->prev = *stack;
	previous_node->next = *stack;
	(*stack)->prev = previous_node;
	previous_node->prev = NULL;
	*stack = previous_node;
}

/**
 * add_nodes -this Fuction Adds the top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	result = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes -this Fuction Adds the top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	result = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds s Fuctionthe top two elements of the stack.
 * @stack: pointing to top node of the stack.
 * @line_number: number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int result;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	result = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = result;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
