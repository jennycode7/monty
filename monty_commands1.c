#include "monty.h"

/**
  * token_check - checks a string
  * @tokens: an array of arrays
  * @x: int
  */
void token_check(char **tokens, int x)
{
	int ret, y;
	char *str;

	for (ret = 0; tokens[ret]; ret++)
	{
		;
	}
	if (ret != 2)
	{
		return;
	}
	else
	{
		str = _strdup(tokens[1]);
		for (y = 0; str[y]; y++)
		{
			if (str[y] >= 'a' && str[y] <= 'z')
			{
				fprintf(stderr, "L%d: usage: push integer\n", x + 1);
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
  * pint_command - pint command
  * @head: head
  * @line_number: line number
  */
void pint_command(stack_t **head, unsigned int line_number)
{
	stack_t *node = *head;
	int x;
	char **tokens;

	tokens = tokenize_string(_strdup(for_instructions[line_number]));
	for (x = 0; tokens[x]; x++)
	{
		;
	}
	if (x == 1)
	{
		while (node->next)
		{
			node = node->next;
		}
		printf("%d\n", node->n);
	}
}
