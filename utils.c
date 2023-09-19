#include "main.h"

/**
 * is_printable - Check if a character is printable.
 * @x: The character to be checked.
 * Return: 1 if printable, 0 otherwise.
 */
int is_printable(char x)
{
if (x >= 32 && x < 127)
{
return (1);
}
return (0);
}

/**
 * append_hexa_code - Append the hexadecimal code to buff.
 * @asc_co: The ASCII code.
 * @buff: The character array to store the result.
 * @a: The current position in the buffer.
 * Return: The number of characters appended (always 3).
 */
int append_hexa_code(char asc_co, char buff[], int a)
{
char carte[] = "0123456789ABCDEF";
if (asc_co < 0)
{
asc_co *= -1;
}
buff[a++] = '\\';
buff[a++] = 'x';
buff[a++] = carte[asc_co / 16];
buff[a] = carte[asc_co % 16];
return (3);
}

/**
 * is_digit - Check if a character is a digit.
 * @b: The character to be checked.
 * Return: 1 if it's a digit, 0 otherwise.
 */
int is_digit(char b)
{
if (b >= '0' && b <= '9')
{
return (1);
}
return (0);
}

/**
 * convert_size_number - Convert a number to a specific size.
 * @num: The number to be converted.
 * @size: The desired size.
 * Return: The converted number.
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
{
return (num);
}
else if (size == S_short)
{
return ((short)num);
}
return ((int)num);
}

/**
 * convert_size_unsgnd - Convert an unsigned number to a specific size.
 * @num: The unsigned number to be converted.
 * @size: The desired size.
 * Return: The converted unsigned number.
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
{
return (num);
}
else if (size == S_short)
{
return ((unsigned short)num);
}
return ((unsigned int)num);
}
