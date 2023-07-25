#include "unixshell.h"

/**
 * memfree - frees all the memory allocated to a program
 * @cmd_opt: pointer to memory to free
 */
void memfree(char **cmd_opt)
{
	size_t i = 0;

	if (cmd_opt == NULL)
		return;

	while (cmd_opt[i])
	{
		free(cmd_opt[i]);
		i++;
	}

	if (cmd_opt[i] == NULL)
		free(cmd_opt[i]);
	free(cmd_opt);
}

/**
 * memfree_exit - frees all the memory allocated and exit.
 * @cmd_opt: cmd_opt memory to free
 */
void memfree_exit(char **cmd_opt)
{
	size_t i = 0;

	if (cmd_opt == NULL)
		return;

	while (cmd_opt[i])
	{
		free(cmd_opt[i]);
		i++;
	}

	if (cmd_opt[i] == NULL)
		free(cmd_opt[i]);
	free(cmd_opt);
	exit(EXIT_FAILURE);
}


/**
 * exit_shellf - Afunction that exits the shell.
 * @ptr_tok: The pointer to tokenized strings.
 */
void exit_shellf(char **ptr_tok)
{
	int status = 0;

	if (ptr_tok[1] == NULL)
	{
		memfree(ptr_tok);
		exit(EXIT_SUCCESS);
	}

	status = _atoi(ptr_tok[1]);
	memfree(ptr_tok);
	exit(status);
}
