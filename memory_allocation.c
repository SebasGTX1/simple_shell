#include "shell.h"
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer to the memory previously allocated
 * @new_size: new size of the new memory block in bytes
 * Return: ptr in the new allocation
 */
void _realloc(char *ptr, int new_size)
{
	char *memcpy = malloc(_strlen(ptr) + 1);
	int i = 0;

	while (ptr[i])
	{
		memcpy[i] = ptr[i];
		i++;
	}
	free(ptr);
	ptr = malloc(new_size);
	i = 0;
	while (memcpy[i])
	{
		ptr[i] = memcpy[i];
		i++;
	}
	free(memcpy);
}

/**
 * _calloc - allocates memory for an array and
 * inicialize it in 0
 * @nmemb: number of elements
 * @size: size of the type elements to be allocated
 * Return: pointer to the allocated memory
 * if nmemb or size is 0, returns NULL
 * if malloc fails, returns NULL
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *memory;

	if (nmemb == 0 || size == 0)
		return (NULL);

	memory = malloc(nmemb * size);

	if (memory == NULL)
	{
		free(memory);
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
		memory[i] = 0;

	return (memory);
}
