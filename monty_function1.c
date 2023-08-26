#include "monty.h"

/**
  * execute_stack - execute stack
  * @instructions: char **
  * @head: head
  * @count: count
  * Return: int
  */
int execute_stack(char **instructions, int count, stack_t **head)
{
	char **tokens;
	char *str;
	int x = 0, y;
	stack_t *copy = *head;

	instruction_t commands[] = {
		{"push", pull_command},
		{"pall", pall_command},
		{NULL, NULL},
	};
	for (x = 0; x < count; x++)
	{
		str = _strdup(instructions[x]);
		tokens = tokenize_string(str);
		for (y = 0; y < 2; y++)
		{
			if (_strcmp(tokens[0], commands[y].opcode) == 0)
			{
				commands[y].f(&copy, x);
				break;
			}
			else if (y != 1)
			{
				continue;
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", x + 1, tokens[0]);
				exit(EXIT_FAILURE);
			}
		}
	}
	return (0);
}


/**
  * tokenize_string - tokenize a string
  * @str: a string
  * Return: returns char **
  */
char **tokenize_string(char *str)
{
	char *form_copy = NULL, *token, *delim = " \n\t";
	char **arg;
	int x = 0, i = 0;

	form_copy = malloc(sizeof(char) * strlen(str));
	if (form_copy == NULL)
	{
		return (NULL);
	}
	_strcpy(form_copy, str);
	token = strtok(str, delim);
	while (token)
	{
		x++;
		token = strtok(NULL, delim);
	}
	arg = malloc(sizeof(char *) * x);
	if (!arg)
	{
		return (NULL);
	}

	token = strtok(form_copy, delim);

	i = 0;
	while (token)
	{
		arg[i] = malloc(sizeof(char) * strlen(token));
		if (!arg[i])
		{
			return (NULL);
		}
		arg[i] = token;
		i++;
		token = strtok(NULL, delim);
	}

	arg[i] = NULL;

	return (arg);
}

/**
  * _strcpy - copies a string
  * @dest: destination
  * @src: source
  * Return: char *
  */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i++] = '\0';

	return (dest);
}

/**
  * _strcmp - compares two string
  * @s1: string 1
  * @s2: string 2
  * Return: an int
  */
int _strcmp(char *s1, char *s2)
{
	int a = 0, b = 0, c = 0, r = 0, lim;

	while (s1[a])
	{
		a++;
	}

	while (s2[b])
	{
		b++;
	}

	if (a <= b)
	{
		lim = a;
	}
	else
	{
		lim = b;
	}

	while (c <= lim)
	{
		if (s1[c] == s2[c])
		{
			c++;
			continue;
		}
		else
		{
			r = s1[c] - s2[c];
			break;
		}

		c++;
	}

	return (r);
}
