/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:03:06 by eieong            #+#    #+#             */
/*   Updated: 2025/02/28 12:32:47 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_bool	pipe_and_fork(t_pipex *pipex, int pipefd[2], pid_t *pid, int index)
{
	if (pipe(pipefd) == -1)
		return (false);
	*pid = fork();
	if (*pid < 0)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (false);
	}
	if (*pid == 0)
	{
		if (index == 0)
			dup2(pipex->in_fd, STDIN_FILENO);
		if (index == pipex->cmd_count - 1)
			dup2(pipex->out_fd, STDOUT_FILENO);
		else
			dup2(pipefd[1], STDOUT_FILENO);
	}
	else
		dup2(pipefd[0], STDIN_FILENO);
	return (true);
}

t_bool	child_process(t_pipex *pipex, char **envp, int index)
{
	int		pipefd[2];
	pid_t	pid;

	if (!pipe_and_fork(pipex, pipefd, &pid, index))
		return (false);
	if (pid == 0)
	{
		if (pipex->cmd_paths[index])
			execve(pipex->cmd_paths[index], pipex->cmd_args[index], envp);
		ft_close_fd(pipex, pipefd);
		ft_cleanup(pipex);
		exit(1);
	}
	else
	{
		close(pipefd[1]);
		close(pipefd[0]);
	}
	return (true);
}

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->cmd_count = 0;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		i;

	if (!envp[0])
		return (ft_error(4), 1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	init_pipex(pipex);
	if (!parse_args(pipex, ac, av))
		return (ft_cleanup(pipex), EXIT_FAILURE);
	if (!parse_cmd_args(pipex, ac, av))
		return (ft_exit_err(pipex, 5));
	if (!parse_cmd_paths(pipex, ac, envp))
		return (ft_exit_err(pipex, 5));
	i = -1;
	while (++i < pipex->cmd_count)
	{
		if (!child_process(pipex, envp, i))
			return (ft_exit_err(pipex, 3));
	}
	i = -1;
	while (++i < pipex->cmd_count)
		waitpid(-1, NULL, 0);
	return (ft_cleanup(pipex), 0);
}
