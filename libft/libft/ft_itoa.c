/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 01:53:18 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	intlen(long int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*ft_strrev(char *str_n)
{
	size_t	i;
	size_t	len;
	int		temp;

	i = 0;
	if (str_n[0] == '-')
		i++;
	len = ft_strlen(str_n);
	while (len >= 0 && i < len)
	{
		len--;
		temp = str_n[i];
		str_n[i] = str_n[len];
		str_n[len] = temp;
		i++;
	}
	return (str_n);
}

char	*ft_itoa(int n)
{
	int			i;
	long int	nb;
	char		*str_n;

	nb = n;
	i = 0;
	str_n = ft_calloc((intlen(nb) + 1), sizeof (char));
	if (!str_n)
		return (NULL);
	if (nb == 0)
		str_n[i] = '0';
	while (nb != 0)
	{
		if (nb < 0)
		{
			str_n[i++] = '-';
			nb *= -1;
		}
		str_n[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	return (ft_strrev(str_n));
}
/*
int	main(void)
{
	int	n = -123456;
	printf("%d\n", n);
	printf("%s\n", ft_itoa(n));
	return (0);
}*/
