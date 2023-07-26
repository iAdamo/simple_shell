#include "unixshell.h"

/**
 * line_token - split and create command
 * @str: delimiter for _strtok
 * @buffer: pointer to input string
 * Return: address to full command
 */
char **line_token(char *buffer, const char *str)
{
	char *cmd_tok = NULL, **command = NULL;
	size_t buff_size = 0;
	size_t i = 0;

	if (buffer == NULL)
		return (NULL);

	buff_size = _strlen(buffer);
	command = malloc(sizeof(char *) * (buff_size + 1));
	if (command == NULL)
	{
		perror("Unable to allocate buffer");
		free(buffer);
		memfree(command);
		exit(EXIT_FAILURE);
	}

	cmd_tok = _strtok(buffer, str);
	while (cmd_tok != NULL)
	{
		command[i] = malloc(_strlen(cmd_tok) + 1);
		if (command[i] == NULL)
		{
			perror("Buffer allocation error");
			memfree(command);
			return (NULL);
		}

		_strcpy(command[i], cmd_tok);
		cmd_tok = _strtok(NULL, str);
		i++;
	}
	command[i] = NULL;
	return (command);
}
