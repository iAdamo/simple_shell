#include "unixshell.h"

/**
 * exec_command - A function that executes a command and their options
 * @cmd_opt: The pointer to tokienized command and options
 * @name: The name of the shell
 * @env: The pointer to the enviromental variables
 * @fact: Number of executed factcodes
 */
void exec_command(char **cmd_opt, char *name, char **env, int fact)
{
	char **pathways = NULL, *full_path = NULL;
	struct stat st;
	unsigned int i = 0;

	if (_strcmp(cmd_opt[0], "env") != 0)
		print_env(env);
	if (stat(cmd_opt[0], &st) == 0)
	{
		if (execve(cmd_opt[0], cmd_opt, env) < 0)
		{
			perror(name);
			memfree_exit(cmd_opt);
		}
	}
	else
	{
		pathways = get_path(env);
		while (pathways[i])
		{
			full_path = _strcat(pathways[i], cmd_opt[0]);
			i++;
			if (stat(full_path, &st) == 0)
			{
				if (execve(full_path, cmd_opt, env) < 0)
				{
					perror(name);
					memfree(pathways);
					memfree_exit(cmd_opt);
				}
				return;
			}
		}
		msgerror(name, fact, cmd_opt);
		memfree(pathways);
	}
}


/**
 * print_env - A function that prints all enviromental variables.
 * @env: The pointer to enviromental variables.
 */
void print_env(char **env)
{
	size_t i = 0, len = 0;

	while (env[i])
	{
		len = _strlen(env[i]);
		write(STDOUT_FILENO, env[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}


/**
 * msgerror - A function that prints message not found.
 * @name: The name of the shell.
 * @fact: Number of fact.
 * @cmd_opt: The pointer to tokenized cmd_opt.
 * Return: Nothing.
 */
void msgerror(char *name, int fact, char **cmd_opt)
{
	char c;

	c = fact + '0';
	write(STDOUT_FILENO, name, _strlen(name));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, cmd_opt[0], _strlen(cmd_opt[0]));
	write(STDOUT_FILENO, ": not found\n", 12);
}
