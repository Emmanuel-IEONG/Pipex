/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:21:20 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:55:27 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printhex(unsigned long n, const char format)
{
	int		count;
	char	*base;

	if (format == 'x' || format == 'p')
		base = "0123456789abcdef";
	else if (format == 'X')
		base = "0123456789ABCDEF";
	if (n < 16)
		return (ft_printchar(base[n]));
	else
	{
		count = ft_printhex((n / 16), format);
		return (count + ft_printhex((n % 16), format));
	}
}

int	ft_printdigit(long n)
{
	int		count;

	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_printdigit(-n) + 1);
	}
	if (n < 10)
		return (ft_printchar(n + '0'));
	else
	{
		count = ft_printdigit(n / 10);
		return (count + ft_printdigit(n % 10));
	}
}

int	print_format(const char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (format == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		count += ft_printptr(va_arg(args, unsigned long), format);
	else if (format == 'd' || format == 'i')
		count += ft_printdigit(va_arg(args, int));
	else if (format == 'u')
		count += ft_printdigit(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		count += ft_printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		count += ft_printpercent();
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), args);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (count);
}
