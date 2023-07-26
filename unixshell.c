#include "unixshell.h"

/**
 * main - main entry to UNIX shell interpreter
 * @ac: number of command line arg(count)
 * @av: an array of command line argument(vector)
 * @env: environmental varible
 * Return: 0 on success
*/
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *buffer, **command_line = NULL;
	int var = 0, line = -1;

	while (1)
	{
		var++;
		show_prompt();
		signal(SIGINT, signal_input);
		buffer = _getline();
		line = _strlen(buffer);
		if (line == EOF)
			_EOF_(buffer);
		else if (*buffer == '\0')
		{
			continue;
		}
		else
		{
			command_line = line_token(buffer, " \0");
			free(buffer);
			if (_strcmp(command_line[0], "exit") != 0)
				exit_shellf(command_line);
			else if (_strcmp(command_line[0], "cd") != 0)
				change_dir(command_line[1]);
			else
				child_process(command_line, av[0], env, var);
		}
		fflush(stdin);
		buffer = NULL;
	}
	if (line == -1)
		return (1);
	return (0);
}


/**
 * show_prompt - A function that prints the prompt_func
 */
void show_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", 9);
}


/**
 * signal_input - function to handle signals e.g Ctr + C signal.
 * @signal: signal to handle.
 */
void signal_input(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\ncisfun$ ", 10);
}

/**
 * _EOF_ - function that checks EOF in a buffer
 * @buffer: pointer to input string.
 */
void _EOF_(char *buffer)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buffer);
	exit(EXIT_SUCCESS);
}
