#include "monty.h"


char **for_instructions = NULL;
int count = 0;

/**
  * main - Entry point
  * @ac: argument count
  * @argv: argument vector
  * Return: returns 0
  */
int main(int ac, char **argv)
{
	stack_t *head = NULL;
	FILE *file;
	int x;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for_instructions = get_command_line(file);
	for (x = 0; for_instructions[x]; x++)
	{
		;
	}
	count = x;
	fclose(file);

	execute_stack(for_instructions, count, &head);

	freer_list(head);
	free_arr(for_instructions);

	return (EXIT_SUCCESS);
}
