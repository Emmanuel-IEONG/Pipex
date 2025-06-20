/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:56:36 by eieong            #+#    #+#             */
/*   Updated: 2025/06/20 15:15:51 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_RDONLY, 0644);
	else if (i == 1)
		file = open(av, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else if (i == 2)
		file = open(av, O_RDWR | O_CREAT | O_APPEND, 0644);
	return (file);
}

void	heredoc_child(char *limiter, t_pipex *pipex, int heredoc_pipe)
{
	int		i;
	char	*line;

	line = NULL;
	while (1)
	{
		i = 0;
		while (i++ < pipex->cmd_count - 1)
			ft_putstr_fd("pipe ", 1);
		ft_putstr_fd("heredoc> ", 1);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter + 1)) == 0
				&& (ft_strlen(limiter) + 1) == ft_strlen(line))
			break ;
		else
			ft_putstr_fd(line, heredoc_pipe);
		free(line);
	}
	close(heredoc_pipe);
	exit(EXIT_SUCCESS);
}

int	get_heredoc_fd(char *limiter, t_pipex *pipex)
{
	int		in_fd;
	int		heredoc_pipe[2];
	pid_t	heredoc_pid;

	in_fd = -1;
	if (pipe(heredoc_pipe) == -1)
		return (-1);
	heredoc_pid = fork();
	if (heredoc_pid < 0)
		return (-1);
	if (heredoc_pid == 0)
		heredoc_child(limiter, pipex, heredoc_pipe[WRITE_END]);
	else
	{
		close(heredoc_pipe[WRITE_END]);
		waitpid(heredoc_pid, NULL, 0);
		in_fd = heredoc_pipe[READ_END];
	}
	return (in_fd);
}
