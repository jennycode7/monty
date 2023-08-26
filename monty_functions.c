#include "monty.h"

/**
  * get_command_line - command line
  * @file: file return
  * Return: char **
  */
char **get_command_line(FILE *file)
{
	char line[100];
	ssize_t lineptr;
	size_t count;
	int x = 1;
	char **instructions;

	instructions = malloc(sizeof(char *) * 20);
	if (!instructions)
	{
		return (NULL);
	}

	count = 0;
	while ((lineptr = read_line(file, line, sizeof(line)) != -1))
	{
		instructions[count] = malloc(sizeof(char) * strlen(line));
		instructions[count] = _strdup(line);
		count++;
		x += 1;
	}
	instructions[count] = NULL;


	return ((char **)instructions);
}

/**
  * _realloc - reallocation of memory
  * @str: pointer
  * @old: ...
  * @new_c: new size
  * Return: ...
  */
void *_realloc(void *str, unsigned int old, unsigned int new_c)
{
	char *p;

	if (!str)
		return (malloc(new_c));
	if (!new_c)
		return (free(str), NULL);
	if (new_c == old)
		return (str);
	p = malloc(new_c);
	if (!p)
		return (NULL);
	old = old < new_c ? old : new_c;
	while (old--)
		p[old] = ((char *)str)[old];
	free(str);
	return (p);
}


/**
  *_strdup - duplicates a string
  * @s: string
  * Return: char *
  */
char *_strdup(char *s)
{
	int x;
	char *copy;

	if (!s)
	{
		return (NULL);
	}

	copy = malloc(sizeof(char) * strlen(s));

	for (x = 0; s[x]; x++)
	{
		copy[x] = s[x];
	}
	copy[x] = '\0';

	return (copy);
}

/**
  * read_line - read a line of a file
  * @file: a file
  * @buffer: a buffer
  * @max_length: maximum length
  * Return: an int
  */
int read_line(FILE *file, char *buffer, size_t max_length)
{
	int c;
	size_t index = 0;

	while ((c = fgetc(file)) != EOF && c != '\n' && index < max_length - 1)
	{
		buffer[index++] = (char)c;
	}
	buffer[index] = '\0';

	if (index == 0 && c == EOF)
	{
		return (EOF);
	}

	return (index);
}
