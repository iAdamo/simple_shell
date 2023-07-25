#include "unixshell.h"
/**
 * child_process - function that creates child processes
 * @cmd_opt: The pointer to tokenized cmd_opt
 * @name: The pointer to the name of shell
 * @env: The pointer to the enviromental variables.
 * @fact: Number of executed fact.
 */

void child_process(char **cmd_opt, char *name, char **env, int fact)
{
	int pid = 0;
	int status = 0;
	int wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		memfree_exit(cmd_opt);
	}
	else if (pid == 0)
	{
		exec_command(cmd_opt, name, env, fact);
		memfree_exit(cmd_opt);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
		{
			memfree_exit(cmd_opt);
		}
		memfree(cmd_opt);
	}
}
