#include "unixshell.h"

/*YOU CAN WRITE IN YOUR CODES HERE...... delete this comment ooo*/


/**
 * exit_shellf - Afunction that exits the shell.
 * @ptr_tok: The pointer to tokenized strings
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
