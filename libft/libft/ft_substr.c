/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:59:04 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:21:34 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	nmemb;

	i = 0;
	if (start > ft_strlen(s))
		nmemb = 0;
	else if (len > ft_strlen(s) - start)
		nmemb = ft_strlen(s) - start;
	else
		nmemb = len;
	str = (char *)malloc((nmemb + 1) * sizeof (char));
	if (!str)
		return (NULL);
	while (i < len && start < ft_strlen(s))
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(int ac, char **av)
{
	(void) ac;
	char	*ptr;

	printf("%s\n", av[1]);
	ptr = ft_substr(av[1], av[2][0], av[3][0]);
	printf("substr : %s\n", ptr);
	if (ptr)
		free (ptr);
	return (0);
}*/
