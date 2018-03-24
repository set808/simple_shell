#include "shell.h"
/**
 * read_line - gets command line from user
 *
 * Return: returns the user input from the command line
 */
char *read_line(void)
{
	char *line = NULL;
	char *result;
	size_t n = 0;

	write (1, "$ ", 2);
	if (getline(&line, &n, stdin) <= 0)
	{
		perror("Error\n");
		exit(99);
	}
	result = _strtok(line, "\n");
	free(line);
	return (result);
}
