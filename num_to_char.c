#include "shell.h"
/**
 * _number_to_char - converts a number into a char*
 * @n: number to be converted
 * Return: the char* to the number digits
 */

char *_number_to_char(int n)
{
	int digits = 1, size = 0, i = 0, n2 = n;
	char *str;

	while (n2 != 0)
	{
		digits *= 10;
		n2 /= 10;
		size++;

	}

	str = malloc(size + 1);

	if (!str)
	{
		free(str);
		return (NULL);
	}

	if (size == 1)
	{
		str[0] = n % 10 + '0';
		str[1] = '\0';
		return (str);
	}
	for (i = size; i >= 0; i--)
	{
		if (i == size)
		{
			str[i] = '\0';
			i--;
		}
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}
