#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - produces output according to a format.
 * @format: character string containing zero or more directives
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */

int _printf(const char *format, ...)
{
	int printed_chars = 0;
	const char *ptr;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
		{
			write(1, ptr, 1);
			printed_chars++;
			continue;
		}

		ptr++;

		if (*ptr == '%')

		{
			write(1, "%", 1);
			printed_chars++;
			continue;
		}

		else if (*ptr == 'c')

		{
			char c = va_arg(args, int);

			write(1, &c, 1);
			printed_chars++;
		}

		else if (*ptr == 's')
		{
			char *str = va_arg(args, char *);
			int len = 0;

			if (str == NULL)
				str = "(null)";

			while (str[len] != '\0')
				len++;

			write(1, str, len);
			printed_chars += len;
		}
	}

	va_end(args);
	return (printed_chars);
}
