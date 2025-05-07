/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printothers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:17:32 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:55:27 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		ft_printchar((int)*str);
		count++;
		str++;
	}
	return (count);
}

int	ft_printpercent(void)
{
	return (write(1, "%", 1));
}

int	ft_printptr(unsigned long n, const char format)
{
	int	count;

	count = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	else
	{
		count += write(1, "0x", 2);
		count += ft_printhex(n, format);
	}
	return (count);
}
