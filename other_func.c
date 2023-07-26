#include "unixshell.h"

/**
 * _strcmp - A funtion that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if strings are the same, 0 if not
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}

/**
 * _strlen - finds the length of the string
 * @str: input string
 * Return: length of the string
 */
int _strlen(char *str)
{
	if (!(*str))
		return (0);
	return (_strlen(str + 1) + 1);
}

/**
 * _strcpy - function that copies a string
 * @dest: destination pointer
 * @src: source pointer
 * Return: an auxilliary pointer of dest
 */
char *_strcpy(char *dest, char *src)
{
	char *aux = dest;

	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (aux);
}

/**
 * _strcat - function that concatenates two strings
 * @dest: strings destination
 * @src: string source
 * Return: return a pointer to new string
*/
char *_strcat(char *dest, char *src)
{
	int i, j;
	char *new_str;

	new_str = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 2));
	if (new_str == NULL)
		return (NULL);
	for (i = 0; dest[i]; i++)
		new_str[i] = dest[i];
	new_str[i] = '/';
	i++;
	for (j = 0; src[j]; j++)
	{
		new_str[i] = src[j];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * _atoi - function that converts string to integer.
 * @str: string.
 * Return: integer
 */
int _atoi(char *str)
{
	int sign = 1;
	unsigned int total = 0;
	char flag = 0;

	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == '-')
			sign *= -1;
		if (*str >= '0' && *str <= '9')
		{
			total = ((total * 10) + (*str - '0'));
			flag = 1;
		}
		else if (flag == 1)
		{
			break;
		}
		str++;
	}
	if (sign < 0)
		total = (-1 * (total));
	return (total);
}
