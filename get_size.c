#include "main.h"
/**
 * get_size - Calculates the size to cast the argument
 * @format: this shall rep Formatted string in which to print the arguments
 * @i: this hsall rep List of arguments to be printed.
 * Return: shall return Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_short;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
