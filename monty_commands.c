#include "monty.h"

/**
  * pull_command - a pulling command
  * @head: stack_t
  * @line_number: line number
  */
void pull_command(stack_t **head, unsigned int line_number)
{
	stack_t *stack;
	char **tokens;
	int y;

	stack = malloc(sizeof(stack_t));
	if (!stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tokens = tokenize_string(_strdup(for_instructions[line_number]));
	token_check(tokens, line_number);
	y = atoi(tokens[1]);
	if ((y == 0 && (_strcmp(tokens[1], "0")) != 0))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number + 1);
		exit(EXIT_FAILURE);
	}
	stack->n = y;
	stack->prev = NULL;
	stack->next = *head;

	if (*head != NULL)
	{
		(*head)->prev = stack;
	}

	*head = stack;
}

/**
 * pall_command - a pall command
 * @head: head
 * @line_number: for line
 */
void pall_command(stack_t **head, unsigned int line_number)
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
		while (node)
		{
			printf("%d\n", node->n);
			node = node->next;
		}
	}
}

/**
 * freer_list - frees alist
 * @head: head
 */
void freer_list(stack_t *head)
{
	stack_t *node = head;
	stack_t *temp;

	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

/**
  * free_arr - frees an array
  * @instructions: double char
  */
void free_arr(char **instructions)
{
	int x;

	for (x = 0; instructions[x]; x++)
	{
		free(instructions[x]);
	}
	free(instructions);
}
