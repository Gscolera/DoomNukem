#include "editor.h"

void	ft_memset(Sint8 *ptr, Sint8 c, Uint32 size)
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

void	editor_itoa(Sint32	num, Sint8 *buff)
{
	Sint8 	*ptr;
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

void	editor_dtoa(double num, Sint8 *buff, Sint8 precision)
{
	Sint8 	*ptr;
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
		ptr[i] = (Sint8)num + 48;
		num -= (Sint32)num;
	}
}

Sint8	*ft_strcat(Sint8 *format, ...)
{
	Sint8		*buff;
	Sint16		size;
	Sint8		precision;
	va_list		list;

	va_start(list, format);
	size = (atoi(format) > 0) ? atoi(format) : 50;
	if (!(buff = (Sint8 *)malloc(size)))
		exit (EDITOR_MEMORY_ERROR);
	ft_memset(buff, 0, size);
	while (*format)
	{
		if (*format == 's')
			strcat(buff, va_arg(list, Sint8*));
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