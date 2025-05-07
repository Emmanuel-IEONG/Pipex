/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:56:23 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	if (siz == 0)
		return (ft_strlen(src));
	else
	{
		while (i < siz - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		while (src[i])
			i++;
		return (i);
	}
}
/*
int	main(int ac, char **av)
{
	(void) ac;

	printf("dest : %s, src : %s\n", av[1], av[2]);
	printf("strlen src = %zu\n", strlcpy(av[1], av[2], 5));
	printf("dest : %s, src : %s\n", av[1], av[2]);
	return (0);
}*/
