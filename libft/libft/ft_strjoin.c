/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:16:18 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		i;

	join = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!join)
		return (NULL);
	i = 0;
	while (*s1)
		join[i++] = *s1++;
	while (*s2)
		join[i++] = *s2++;
	join[i] = '\0';
	return (join);
}
/*
int	main(int ac, char **av)
{
	(void) ac;
	char	*ptr;

	printf("s1 : %s, s2 : %s\n", av[1], av[2]);
	ptr = ft_strjoin(av[1], av[2]);
	printf("join : %s\n", ptr);
	if (ptr)
		free (ptr);
	return (0);
}*/
