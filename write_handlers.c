#include "main.h"
/**
 *handle_write_char - this code shall put strs
 *@buffer: this shall represent the array of puts
 *@c: this shall represent the chars put
 *@flags: this shall calc the flag actv
 *@width: this shall represent the wdth
 *@precision: this shall represent the spec of precisio
 *@size: this shall represnt the spec of size
 *Return: it shall return strs
 */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size)
{
int x = 0;
char add = ' ';
UNUSED(precision);
UNUSED(size);
if (flags & F_ZERO)
{
add = '0';
}
buffer[x++] = c;
buffer[x] = '\0';
if (width > 1)
{
buffer[BUFF_SIZE - 1] = '\0';
for (; x < width - 1; x++)
{
buffer[BUFF_SIZE - x - 2] = add;
}
if (flags & F_MINUS)
{
return (write(1, &buffer[0], 1) +
write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
}
else
return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
write(1, &buffer[0], 1));
}
return (write(1, &buffer[0], 1));
}
/**
 *write_number - this code shall orint strs
 *@ind: this represent the chars types
 *@is_negative: this shall represent the args
 *@buffer: this shall represent the array handled
 *@flags:  this shall rwpresent the flags
 *@width: this shall represent the width toget
 *@precision: this shall represent the spec of percise
 *@size: this shall represent the size
 *Return: it shall retrun the printed chars
 */
int write_number(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size)
{
int leng = BUFF_SIZE - ind - 1;
char add = ' ', extra_ch = 0;
UNUSED(size);
if ((flags & F_ZERO) && !(flags & F_MINUS))
{
add = '0';
}
if (is_negative)
{
extra_ch = '-';
}
else if (flags & F_PLUS)
{
extra_ch = '+';
}
else if (flags & F_SPACE)
{
extra_ch = ' ';
}
return (write_num(ind, buffer, flags, width, precision, length,
add, extra_ch));
}
/**
 ** write_num - Write a number using a bufffer
 *@ind: this shall represent the no of buffs
 *@buffer: this shall represent the buff
 *@flags: this shall represnt rhe flafs
 *@width: this shall repesent the qwidth of arr
 *@prec: this shall represent the precision spec
 *@length: this shall represent the len of nos
 *@padd: this repesent the add
 *@extra_c: the shall represent the plus chars
 *Return: this code shall return puted chars
 */

int write_num(int ind, char buffer[], int flags, int width, int prec,
int length, char padd, char extra_c)
{
int x;
int add_start = 1;
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0'
&& width == 0)
return (0);
if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
buffer[ind] = padd ' ';
if (prec > 0 && prec < length)
padd = ' ';
while (prec > length)
{
buffer[--ind] = '0', length++;
}
if (extra_c != 0)
length++;
if (width > length)
{
for (x = 1; x < width - length + 1; x++)
buffer[x] = padd;
buffer[i] = '\0';
if (flags & F_MINUS && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) +
write(1, &buffer[1], x - 1));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[1], x - 1) +
write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--add_start] = extra_c;
return (write(1, &buffer[add_start], x - add_start) +
write(1, &buffer[ind], length - (1 - add_start)));
}
}
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length));
}
/**
 *write_unsgnd - this code shall put nos
 *@is_negative: this shall represent the -ve nums
 *@ind: this shall represent the set of nums
 *@buffer: this shall represent the chars array
 *@flags: this hsall represent the specs flgs
 *@width: this shall represent the wdth
 *@precision: this shall represent the presicse
 *@size: this shall represent the size of chars
 *Return: it hsall return the chars written
 */
int write_unsgnd(int is_negative, int ind,
char buffer[], int flags, int width, int precision, int size)
{
int len = BUFF_SIZE - ind - 1, x = 0;
char add = ' ';
UNUSED(is_negative);
UNUSED(size);
if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
{
return (0);
}
if (precision > 0 && precision < len)
add = ' ';
while (precision > len)
{
buffer[--ind] = '0';
len++;
}
if ((flags & F_ZERO) && !(flags & F_MINUS))
{
padd = '0';
}
if (width > length)
{
for (x = 0; x < width - length; x++)
{
buffer[x] = add;
}
buffer[x] = '\0';
if (flags & F_MINUS)
{
return (write(1, &buffer[ind], len) +
write(1, &buffer[0], x));
}
else
{
return (write(1, &buffer[0], x) +
write(1, &buffer[ind], len));
}
}
return (write(1, &buffer[ind], len));
}
/**
 *write_pointer - this code shall write a memo add
 *@buffer: this shall represent the chars of array
 *@ind: this hsall represent the index of nums
 *@length: this shall represent the len of nums
 *@width: this shall represent the wdth of nums
 *@flags: this shall represent the flgs
 *@padd: this hsall represent the hcars of padds
 *@extra_c: this shall represent the extra
 *@padd_start: this represent pad start buffer
 *Return: it shall return chars
 */
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start)
{
int x;
if (width > length)
{
for (x = 3; x < width - length + 3; x++)
buffer[x] = padd;
buffer[x] = '\0';
if (flags & F_MINUS && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], length) +
write(1, &buffer[3], x - 3));
}
else if (!(flags & F_MINUS) && padd == ' ')
{
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[3], x - 3) +
write(1, &buffer[ind], length));
}
else if (!(flags & F_MINUS) && padd == '0')
{
if (extra_c)
buffer[--padd_start] = extra_c;
buffer[1] = '0';
buffer[2] = 'x';
return (write(1, &buffer[padd_start], x - padd_start) +
write(1, &buffer[ind], length - (1 - padd_start) - 2));
}
}
buffer[--ind] = 'x';
buffer[--ind] = '0';
if (extra_c)
buffer[--ind] = extra_c;
return (write(1, &buffer[ind], BUFF_SIZE - ind - 1));
}
