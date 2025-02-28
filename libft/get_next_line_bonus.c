/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:43:22 by eieong            #+#    #+#             */
/*   Updated: 2025/01/14 11:24:45 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line_bonus.h"

static char	*read_and_stash(int fd, char *stash, char *buffer)
{
	ssize_t	check_read;
	char	*temp;

	check_read = 1;
	while (check_read > 0)
	{
		check_read = read(fd, buffer, BUFFER_SIZE);
		if (check_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (check_read == 0)
			break ;
		buffer[check_read] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (stash);
}

static char	*stash_left(char *line)
{
	char	*stash;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line));
	if (*stash == 0)
	{
		free (stash);
		stash = NULL;
	}
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash[1024];

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash[fd]);
		free(buffer);
		stash[fd] = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_and_stash(fd, stash[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	stash[fd] = stash_left(line);
	return (line);
}
