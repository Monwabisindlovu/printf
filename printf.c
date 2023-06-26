#include "main.h"

/**
 * print_format - Prints a character or string depending on the
 * format specifier.
 *
 * @format: A character string containing directives.
 * @args: A va_list containing the arguments.
 *
 * Return: The number of characters printed.
 */
int print_format(const char *format, va_list args)
{
int printed_chars = 0;

switch (*format)
{
case 'c':
printed_chars += _putchar(va_arg(args, int));
break;
case 's':
{
char *str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
{
printed_chars += _putchar(*str);
str++;
}
}
break;
case '%':
printed_chars += _putchar('%');
break;
default:
printed_chars += _putchar('%');
printed_chars += _putchar(*format);
break;
}

return (printed_chars);
}

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
printed_chars += _putchar(*format);
}
else
{
format++;
printed_chars += print_format(format, args);
}
format++;
}

va_end(args);

return (printed_chars);
}

