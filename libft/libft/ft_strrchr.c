/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:32:13 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] != (char)c && s[i])
			i++;
		if (s[i] == (char)c)
			j = i;
		if (s[i])
			i++;
	}
	if (s[j] == (char)c)
		return ((char *)&s[j]);
	else
		return (NULL);
}
/*
int main(int ac, char **av)
{
    (void) ac;
    printf("search '%c' in '%s'\n", 'a', av[1]);
    printf("%s\n", ft_strrchr(av[1], 'a'));
    return (0);
}*/
