#include "unixshell.h"

/**
  * change_dir - function that changes working directory.
  * @path_name: new current working directory.
  * Return: 0 on success, -1 on failure.
  */
int change_dir(const char *path_name)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path_name == NULL)
		path_name = getcwd(buf, size);
	if (chdir(path_name) == -1)
	{
		perror(path_name);
		return (98);
	}
	return (1);
}
