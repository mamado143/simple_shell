#include"Myshell.h"
/**
 * compare_strings - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: Result of the comparison.
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * calculate_string_length - Calculate the length of a string.
 * @str: Input string.
 * Return: Length of the string.
 */
size_t calculate_string_length(const char *str)
{
	size_t length = 0;

	while (str[length++]);
	return (length - 1);
}
