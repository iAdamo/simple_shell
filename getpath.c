#include "unixshell.h"
/**
 * get_path - function to gets the full value from enviromental variable PATH
 * @env: The pointer to enviromental variables.
 * Return: All tokenized pathways for command.
 */
char **get_path(char **env)
{
	char *pathvalue = NULL, **pathways = NULL;
	unsigned int i = 0;

	pathvalue = _strtok(env[i], "=");
	while (env[i])
	{
		if (_strcmp(pathvalue, "PATH"))
		{
			pathvalue = _strtok(NULL, "\n");
			pathways = line_token(pathvalue, ":");
			return (pathways);
		}
		i++;
		pathvalue = _strtok(env[i], "=");
	}
	return (NULL);
}
