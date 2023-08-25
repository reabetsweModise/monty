#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - the interpreter fo the monty code
* @argc: number of arguments
* @argv: the location of the monty file
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t sizer = 0;
	ssize_t line_reader = 1;
	stack_t *stack = NULL;
	unsigned int counters = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (line_reader > 0)
	{
		content = NULL;
		line_reader = getline(&content, &sizer, file);
		bus.content = content;
		counters++;
		if (line_reader > 0)
		{
			execute(content, &stack, counters, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}

