/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:27:33 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i])
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
/*
static void	test(unsigned int i, char *a)
{
	*a += i;
}
int	main(int ac, char **av)
{
	(void) ac;
	char	*str;

	str = ft_strdup(av[1]);
	ft_striteri(str, test);
	printf("%s\n", str);
	if (str)
		free(str);
	return (0);
}*/
