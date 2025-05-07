/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:26:05 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	}
	else
		ft_memcpy((unsigned char *)dest, (unsigned char *)src, n);
	return (dest);
}
/*
int	main(int ac, char **av)
{
	(void) ac;

	printf("dest = %s, source = %s\n", &av[1][3], &av[1][0]);
	ft_memmove(&av[1][3], &av[1][0], 8);
	printf("av[1] = %s\n", av[1]);
	return (0);
}*/
