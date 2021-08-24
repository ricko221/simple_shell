#include "shell.h"

/**
 * _getline - Gets line of user input
 * Return: Pointer to buffer of user input
 */
char *_getline(void)
{
	int temp;
	char *line = NULL;
	size_t size = 0;

	temp = getline(&line, &size, stdin);
	if (temp == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}
/**
 * split_line - Splits line into args
 * @line: Line of user input
 * Return: Array of args of user input
 */
char **split_line(char *line)
{
	size_t buffer_size = TOKENS_BUFFER_SIZE;
	char **tokens = malloc(sizeof(char *) * buffer_size);
	char *token;
	int pos = 0;

	if (!tokens)
	{
		perror("Could not allocate space for tokens\n");
		exit(0);
	}
	token = strtok(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[pos] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
		pos++;
	}
	tokens[pos] = NULL;
	return (tokens);
}
