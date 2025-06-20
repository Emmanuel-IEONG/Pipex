/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:03:06 by eieong            #+#    #+#             */
/*   Updated: 2025/06/20 14:36:15 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_bool	pipe_and_fork(t_pipex *pipex, int pipefd[2], pid_t *pid, int index)
{
	*pid = fork();
	if (*pid < 0)
		return (ft_close_fd(pipex, pipefd), false);
	if (*pid == 0)
	{
		if (index == 0)
		{
			if (pipex->in_fd == -1)
			{
				ft_close_fd(pipex, pipefd);
				ft_cleanup(pipex);
				exit (EXIT_FAILURE);
			}
			dup2(pipex->in_fd, STDIN_FILENO);
			dup2(pipefd[WRITE_END], STDOUT_FILENO);
		}
		else if (index == pipex->cmd_count - 1)
		{
			if (dup2(pipex->out_fd, STDOUT_FILENO) == -1)
			{
				ft_close_fd(pipex, pipefd);
				ft_cleanup(pipex);
				exit (EXIT_FAILURE);
			}
		}
		else
			dup2(pipefd[WRITE_END], STDOUT_FILENO);
		ft_close_fd(pipex, pipefd);
	}
	else
	{
		pipex->last_pid = *pid;	
		dup2(pipefd[READ_END], STDIN_FILENO);
	}
	return (true);
}

t_bool	child_process(t_pipex *pipex, char **envp, int index)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		return (false);
	if (!pipe_and_fork(pipex, pipefd, &pid, index))
		return (false);
	if (pid == 0)
	{
		if (pipex->cmd_paths[index])
			execve(pipex->cmd_paths[index], pipex->cmd_args[index], envp);
		ft_close_fd(pipex, pipefd);
		ft_cleanup(pipex);
		exit(127);
	}
	else
	{
		close(pipefd[WRITE_END]);
		close(pipefd[READ_END]);
	}
	return (true);
}

void	init_pipex(t_pipex *pipex)
{
	pipex->in_fd = -1;
	pipex->out_fd = -1;
	pipex->cmd_count = 0;
	pipex->here_doc = 0;
	pipex->last_status = 0;
	pipex->last_pid = 0;
	pipex->cmd_paths = NULL;
	pipex->cmd_args = NULL;
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;
	int		i;
	int		status;
	
	if (!envp[0])
		return (ft_error(4), 1);
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (EXIT_FAILURE);
	init_pipex(pipex);
	if (ac < 5)
		return (ft_exit_err(pipex, 1, 1));	
	parse_args(pipex, ac, av);
	if (!parse_cmd_args(pipex, ac, av) || !parse_cmd_paths(pipex, ac, envp))
		return (ft_exit_err(pipex, 5, 1));
	i = -1;
	while (++i < pipex->cmd_count)
	{
		if (!child_process(pipex, envp, i))
			return (ft_exit_err(pipex, 3, 1));
	}
	i = -1;
	while (++i < pipex->cmd_count)
	{
		if (pipex->last_pid == waitpid(-1, &status, 0))
			pipex->last_status = WEXITSTATUS(status);
	}
	status = pipex->last_status;
	return (ft_cleanup(pipex), status);
}
