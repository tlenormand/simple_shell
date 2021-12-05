#include "main.h"

/**
 * _strlen - function that returns the length of a string
 * @str: string to returns the length
 * Return: Return the length of the string
 */

int _strlen(char *str)
{
	int i = 0;

	while (*str != 0)
		str++, i++;

	return (i);
}


/**
 * _strcat - function that concatenates two strings
 * @dest: destination to concatenate
 * @src: source to concatenate
 * Return: the result concatenate
 */

char *_strcat(char *dest, char *src)
{
	int j, length = 0;

	while (dest[length] != '\0')
		length++;

	for (j = 0; src[j] != '\0'; j++)
		dest[length + j] = src[j];

	dest[length + j] = '\0';

	return (dest);
}


/**
 * _strdup - function returns a pointer to a newly allocated space in memory
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: the string duplicated
 */

char *_strdup(char *str)
{
	int i;
	char *new = NULL;

	if (str == 0)
		return (NULL);

	new = (char *)malloc(sizeof(char) * (_strlen(str) + 1));
	if (new == NULL)
		return (NULL);

	for (i = 0; i < _strlen(str); i++)
		*(new + i) = *(str + i);

	*(new + i) = '\0';

	return (new);
}


/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: destination to return
 * @src: source to copy
 * Return: the pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = src[i];

	return (dest);
}


/**
 * _strcmp - function that compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: the comparison
 */

int _strcmp(char *s1, char *s2)
{

	int i;

	for (i = 0; s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0'); i++)
		continue;

	return (s1[i] - s2[i]);
}
