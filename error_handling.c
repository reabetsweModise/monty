#include "monty.h"
/**
 * err -this Fuction Error code printer based on error code.
 * @error_code: error code cases are as follows:
 * (Code 1) - No file provided or more than 1 file provided.
 * (Code 2) - file Unreadble/Cant open.
 * (Code 3) - invaid Instructions in file.
 * (Code 4) - program unable to malloc more memory.
 * (Code 5) - "push" parameter not int
 * (Code 6) - Pit stack empty.
 * (Code 7) - Pop stack empty.
 * (Code 8) - stack too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *opcode;
	int line_number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			line_number = va_arg(ag, int);
			opcode = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err -this Fuction  number error handling.
 * @error_code: The error code cases are as follows
 * (Code 9) - Stack has been Divided by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *opcode;
	int line_number;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			line_number = va_arg(ag, unsigned int);
			opcode = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_number, opcode);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err -this Fuction String error handling.
 * @error_code: The error code cases are as follows
 * (Code 10) ~> Node number out of ASCII bounds.
 * (Code 11) ~> Empty stack.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int line_number;

	va_start(ag, error_code);
	line_number = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
