/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cleanup_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:40:48 by eieong            #+#    #+#             */
/*   Updated: 2025/02/28 12:32:46 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_close_fd(t_pipex *pipex, int pipefd[2])
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(pipex->in_fd);
	close(pipex->out_fd);
}

void	ft_error(int err)
{
	if (err == 1)
		ft_putstr_fd("pipex error : Invalid number of arguments.\n", 2);
	else if (err == 2)
		ft_putstr_fd("pipex error : Command not found\n", 2);
	else if (err == 3)
		ft_putstr_fd("pipex error : Pipe or fork failed\n", 2);
	else if (err == 4)
		ft_putstr_fd("Cannot execute binary file\n", 2);
	else if (err == 5)
		ft_putstr_fd("Malloc failed\n", 2);
}

t_bool	ft_exit_err(t_pipex *pipex, int err)
{
	ft_cleanup(pipex);
	ft_error(err);
	exit(1);
	return (false);
}

void	ft_freetabcmd(char **tab, int cmd_count)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_cleanup(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1)
		close(pipex->out_fd);
	if (pipex->cmd_paths != NULL)
		ft_freetabcmd(pipex->cmd_paths, pipex->cmd_count);
	if (pipex->cmd_args != NULL)
	{
		while (i < pipex->cmd_count)
		{
			ft_freetab(pipex->cmd_args[i]);
			i++;
		}
		free(pipex->cmd_args);
	}
	free(pipex);
}
