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
