/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:10:28 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:43:07 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	result_format(const char *format, va_list args)
{
	int		count;
	char	ptr;

	ptr = *(format + 1);
	count = 0;
	if (ptr == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (ptr == 'd' || ptr == 'i')
		count = ft_putnbr(va_arg(args, int));
	else if (ptr == 'p')
		count = ft_putptr(va_arg(args, void *));
	else if (ptr == 'x' || ptr == 'X' || ptr == 'u')
		count = ft_putunsigned_hex(va_arg(args, unsigned int), ptr);
	else if (ptr == '%')
		count = ft_putchar(ptr);
	else if (ptr == 's')
		count = ft_putstr(va_arg(args, char *));
	else
		count = ft_putchar(*format);
	return (count);
}

int	is_valid(char c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = "cdsuixXp%%";
	while (ptr[i])
	{
		if (ptr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == '\0')
		{
			count = -1;
			break ;
		}
		else if (*format == '%')
		{
			count += result_format(format++, args);
			if (is_valid(*format))
				format++;
		}
		else
			count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}
