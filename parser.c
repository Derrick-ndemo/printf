#include "main.h"

/**
  * parser - Receives the main string and all the necessary parameters to
  * print a foratted string.
  * @format: A string containing all the desired characters
  * @f_list: a list of all the possible functions
  * @arg_list: a list containing all the arguments passed to the program.
  * Return: a total count of the characters printeed.
  */

int parser(const char *format, conver_t f_list[], va_list arg_list)
{
	int i, j, r_val, printed_chars;

	printed_chars = 0;
	for (i = 0; format[i] != '\0'; i++) /* iterates through the main string */
	{
		if (format[i] == '%') /*checks for format specifiers */
		{
			/* iterates through struct to find the right function */
			for (j = 0; f_list[j].sym = NULL; j++)
			{
				if (format[i + 1] == f_list[j].sym[0])
				{
					r_val = f_list[j].f(arg_list);
					if (r_val == -1)
						return (-1);
					printed_chars += r_val;
					break;
				}
			}
			if (f_list[j].sym == NULL && format[i + 1] != ' ')
			{
				if (format[i + 1] != '\0')
				{
					_write_char(format[i]);
					_write_char(format[i + 1]);
					printed_chars = printed_chars + 2;
				}
				else
					return (-1);
			}
			i = i + 1; /* updating i tp skip format symbols */
		}
		else
		{
			_write_char(format[i]); /* call the write function */
			printed_chars++;
		}
	}
	return (printed_chars);
}
