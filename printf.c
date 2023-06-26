#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
int printed_chars = 0;
va_list args;

va_start(args, format);

if (format == NULL)
return (-1);

while (*format)
{
if (*format != '%')
{
_putchar(*format);
printed_chars++;
}
else
{
format++;

switch (*format)
{
case 'c':{
char c = va_arg(args, int);
_putchar(c);
printed_chars++;
break;
}
case 's':
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
_putchar(*str);
printed_chars++;
str++;
}
break;
}
case '%':
_putchar('%');
printed_chars++;
break;
default:
_putchar('%');
_putchar(*format);
printed_chars += 2;
break;
}
}
format++;
}

va_end(args);

return (printed_chars);
}

