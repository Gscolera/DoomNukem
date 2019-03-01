#include "editor.h"

void	ft_memset(char *ptr, char c, Uint32 size)
{
	if (!ptr)
		return ;
	while (size--)
		ptr[size] = c;
}

static Uint16 get_int_size(Sint32 num)
{
	Uint32 size;

	size = (num < 0) ? 1 : 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		size++;
	}
	return (size);
}

void	editor_itoa(Sint32	num, char *buff)
{
	char 	*ptr;
	Uint16	i;

	ptr = buff;
	
	i = get_int_size(num);
	while (*ptr)
		ptr++;
	while (i--)
	{
		ptr[i] = (num < 0) ? -num % 10 + 48 : num % 10 + 48;
		if (num < 0 && i == 0)
			ptr[i] = 45;
		num /= 10;
	}
}

void	editor_dtoa(double num, char *buff, char precision)
{
	char 	*ptr;
	Uint16	i;

	i = 0;
	ptr = buff;
	editor_itoa(num, buff);
	num = num - (Sint32)num;
	while (*ptr)
		ptr++;
	ptr[i] = '.';
	while (i++ < precision)
	{
		num *= 10;
		ptr[i] = (char)num + 48;
		num -= (Sint32)num;
	}
}

char	*ft_strcat(char *format, ...)
{
	char		*buff;
	Sint16		size;
	char		precision;
	va_list		list;

	va_start(list, format);
	size = (atoi(format) > 0) ? atoi(format) : 50;
	if (!(buff = (char *)malloc(size)))
		exit (EDITOR_MEMORY_ERROR);
	ft_memset(buff, 0, size);
	while (*format)
	{
		if (*format == 's')
			strcat(buff, va_arg(list, char*));
		else if (*format == 'd')
			editor_itoa(va_arg(list, Sint32), buff);
		else if (*format == 'f')
		{
			precision = atoi(format + 1);
			precision = (precision) ? precision : 2;
			editor_dtoa(va_arg(list, double), buff, precision);
		}
		format++;
	}
	va_end(list);
	return (buff);
}