#include "main.h"
/**
 *is_printable - this code shall chack if chars are printables
 *@x: this represent the characters to be printed
 *Return: it shall return zero in success and 1 if prints
 */
int is_printable(char x)
{
if (x >= 32 && c < 127)
{
return (1);
}
return (0);
}
/**
 *append_hexa_code - this code shall put the code to buff
 *@buff: this rerpesent the characters of arrays
 *@a: this shall represent the list
 *@asc_co: this shall repesent the code of assci
 *Return: it shall return three in success
 */
int append_hexa_code(char asc_co, char buff[], int a)
{
char carte[] = "0123456789ABCDEF"
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
 *is_digit - this code shall verify if chars is digi
 *@b: this represent the chars to be checked
 *Return: it hsall return 0 if NULL or 1 in chars
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
 * convert_size_number - this code shall set a no to siz
 *@num: this shall represent the no to be launched
 *@size: this shall represent the size of int
 *Return: it shall retrun the value of int
 */
long int convert_size_number(long int num, int size)
{
if (size == S_LONG)
{
return (num);
}
else if (size == S_SHORT)
{
return ((short)num);
}
return ((int)num);
}
/**
 *convert_size_unsgnd - this code shall put no to spec size
 *@num: this represent the num to be put
 *@size: this shall represent the size to be put
 *Return: it shall return the nos
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
if (size == S_LONG)
{
return (num);
}
else if (size == S_SHORT)
{
return ((unsigned short) num);
}
return ((unsigned int)num);
}