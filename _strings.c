#include "shell.h"
/**
 * _strcat - concatenates two strings
 * @s1: string one
 * @s2: string two
 * Return: no return
 */
void _strcat(char *s1, char *s2)
{
	size_t j = 0, i = _strlen(s1);

	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
}
/**
 * _strcpy - copy a string
 * @src: string
 * @dest: string
 * Return: copy string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (i >= 0)
	{
		*(dest + i) = *(src + i);
		if  (*(src + i) == '\0')
			break;
		i++;
	}
	return (dest);
}

/**
 * _strlen - gives the lenght of a string
 * @str: string
 * Return: lenght of a string
 */
size_t _strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (1 + _strlen(str + 1));
}

/**
 * _strncmp - Function that compares two strings
 * @s1: pointer to string
 * @s2: pointer to string
 * @n: number of positions to compare
 * Return: 0 if s1 == s2 or -1 in otherwise
 */
int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}
/**
 * _strcmp - Function that compares two strings
 * @s1: pointer to string
 * @s2: pointer to string
 * Return: 0 if s1 == s2 or -1 in otherwise
 */
int _strcmp(const char *s1, const char *s2)
{
	size_t i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
			++i;
		else
			return (s1[i] - s2[i]);
	}
	return (0);
}
