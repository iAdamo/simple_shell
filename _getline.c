#include "unixshell.h"
/**
* _getline - reads  an entire line from stream
* Return: the input on a buffer
*/
char *_getline()
{
	size_t i; 
	int read_line, buffsize = 10240;
	char c = 0, *buffer, *buf;

	buffer = malloc(buffsize);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		read_line = read(STDIN_FILENO, &c, 1);
		if (read_line == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		buffer[i] = c;
		if (buffer[0] == '\n')
			return (enter(buffer));
		if (i >= buffsize)
		{
			buffer = realloc(buffer, (buffsize + 2));
			if (buffer == NULL)
			{
				free(buffer);
				return (NULL);
			}
		}
	}
	buffer[i] = '\0';
	buf = void_void_space(buffer);
	free(buffer);
	void_hash(buf);
	return (buf);
}
/**
 * enter - Handles newline character input
 * @string: String to be handled
 * Return: Empty string
 */
char *enter(char *string)
{
	free(string);
	return ("\0");
}

/**
 * void_space - Modifies the input string to remove preceeding white_spaces
 * @str: Input to be modifies
 * Return: Returns the modified string
 */
char *void_space(char *str)
{
	int i = 0, j = 0;
	char *buff;

	buff = malloc(sizeof(char) * (_strlen(str) + 1));
	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	while(str[i] == ' ')
	{
		while (str[i + 1] != '\0');
		{
			buff[j] = str[i];
			j++;
			i++;
		}
		i++;
	}
	buff[j] = '\0';
	if (buff[0] == '\0' || buff[0] == '#')
	{
		free(buff);
		return ("\0");
	}
	return (buff);
}
/**
 * void_hash - function that removes everything after '#'
 * @buff: input buffer
 * Return: nothing
 */
void void_hash(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#' && buff[i - 1] == ' ' && buff[i + 1] == ' ')
		{
			buff[i] = '\0';
		}
	}
}
