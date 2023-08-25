#include "monty.h"

/**
 * open_file - file opener
 * @file_name: the namepath of the file
 * Return: returns void
 */

void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);

	read_file(fd);
	fclose(fd);
}


/**
 * read_file - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void read_file(FILE *fd)
{
	int line_number, storage_format = 0;
	char *buffer = NULL;
	size_t buffer_length = 0;

	for (line_number = 1; getline(&buffer, &buffer_length, fd) != -1; line_number++)
	{
		storage_format = parse_line(buffer, line_number, storage_format);
	}
	free(buffer);
}


/**
 * parse_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: lines from the file
 * @line_number: the line number
 * @storage_format:  storage storage_format. 0 Nodes will be entered as a stack.
 * 1 nodes will be entered as a queue.
 * Return: Returns 0 when opcode is stack. 1 when queue.
 */

int parse_line(char *buffer, int line_number, int storage_format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (storage_format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, storage_format);
	return (storage_format);
}

/**
 * find_func - finds the function opcode
 * @opcode: instruction
 * @value: argument of opcode
 * @storage_format:  storage storage_format. If 0 Nodes will be entered as a stack.
 * @ln: line number if 1 nodes will be entered as a queue.
 * Return: returns void.
 */
void find_func(char *opcode, char *value, int ln, int storage_format)
{
	int loop_counter;
	int opcode_flag;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (opcode_flag = 1, loop_counter = 0; func_list[loop_counter].opcode != NULL; loop_counter++)
	{
		if (strcmp(opcode, func_list[loop_counter].opcode) == 0)
		{
			call_fun(func_list[loop_counter].f, opcode, value, ln, storage_format);
			opcode_flag = 0;
		}
	}
	if (opcode_flag == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: string representing a numeric value.
 * @ln: line number for the instruction.
 * @storage_format: Format specifier.
 */
void call_fun(op_func func, char *op, char *val, int ln, int storage_format)
{
	stack_t *stack_node;
	int opcode_flag;
	int loop_counter;

	opcode_flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			opcode_flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (loop_counter = 0; val[loop_counter] != '\0'; loop_counter++)
		{
			if (isdigit(val[loop_counter]) == 0)
				err(5, ln);
		}
		stack_node = create_node(atoi(val) * opcode_flag);
		if (storage_format == 0)
			func(&stack_node, ln);
		if (storage_format == 1)
			add_to_queue(&stack_node, ln);
	}
	else
		func(&head, ln);
}
