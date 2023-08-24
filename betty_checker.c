#include "main.h"
/**
 * _strspn - Entry point
 * @s: input
 * @accept: input
 * Return: Always 0 (Success)
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int character;

	while (*s)
	{
		for (character = 0; accept[character]; character++)
		{
			if (*s == accept[character])
			{
				count++;
				break;
			}
			else if (accept[character + 1] == '\0')
				return (count);
		}
		s++;
	}
	return (count);
}

