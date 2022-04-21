#include "shell.h"
/**
 * _isalpha - checks for alphabetic character
 * @s: string
 * Return: 0 (Success) 1 (Fail)
*/
int _isalpha(char *s)
{
	int i = 0;

	for (; s[i]; i++)
	{
		if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90))
			return (0);
	}
	return (1);
}
/**
 * _atoi - converts a string to an integer
 * @s: string.
 * Return: integer.
 */
int _atoi(char *s)
{

	unsigned int count = 0, t = 0, i = 0, sig = 1, m = 1, intt = 0;

	while (*(s + count) != '\0')
	{

		if (t > 0 && (*(s + count) < '0' || *(s + count) > '9'))
		{
			break;
		}
		if (*(s + count) == '-')
		{
			return (-1);
		}

		if (*(s + count) >= '0' && *(s + count) <= '9')
		{
			if (t > 0)
			{
				m *= 10;
			}
			t++;
		}
	count++;
	}

		for (i = count - t; i < count; i++)
		{
			intt = intt + (*(s + i) - 48) * m;
			m /= 10;
		}

return (sig * intt);
}
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
