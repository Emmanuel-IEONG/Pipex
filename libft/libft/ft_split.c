/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:13:18 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	int		i;

	start = 0;
	i = 0;
	split = (char **)malloc((count_words(s, c) + 1) * sizeof (char *));
	if (!split)
		return (NULL);
	while (s[start])
	{
		while (s[start] == c && s[start])
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		if (s[start])
			split[i++] = ft_substr(&s[start], 0, end - start);
		start = end;
	}
	split[i] = 0;
	return (split);
}
/*
int	main(int ac, char **av)
{
	char	**ptr;
	int	i;

	(void) ac;
	i = 0;
	ptr = ft_split(av[1], av[2][0]);
	while (ptr[i] != 0)
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	i = 0;
	if (ptr)
	{
		while (ptr[i])
		{
			free(ptr[i]);
			i++;
		}
		free(ptr);
	}
	return (0);
}*/
