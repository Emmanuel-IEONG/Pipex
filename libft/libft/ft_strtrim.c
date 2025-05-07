/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:58:32 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	check_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check_set(s1[start], set))
		start++;
	while (end > start && check_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof (*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Wrong number of arg");
		return (1);
	}
	char s[] = "lorem \n ipsum \t dolor \n sit \t amet";
	printf("s1 : %s\nset : %s\n", s, av[1]);
	char 	*str = ft_strtrim(s, av[1]);
	printf("strtrim : %s\n", str);
	if (str)
		free(str);
	return (0);
}*/
