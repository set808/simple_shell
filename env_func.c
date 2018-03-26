#include "shell.h"
/**
 * _getenv - searches environment list for variable name
 * @name: name of the variable
 *
 * Return: returns a pointer to the corresponding value;
 */
char *_getenv(char *name)
{
	unsigned int y;
	char *match, *delim, *copy;
	path_t *temp;

	match = NULL;
	delim = "=";
	temp = env;

	while (temp)
	{
		y = 0;
		while (name[y])
		{
			if (name[y] != temp->dir[y])
				break;
			if (name[y + 1] == '\0' && temp->dir[y + 1] == '=')
				match = temp->dir;
			y++;
		}
		if (match)
			break;
		temp = temp->next;
	}
	copy = _strdup(match);
	_strtok(copy, delim);
	match = _strtok(NULL, delim);
	return (match);
}
