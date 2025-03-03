/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:03:06 by eieong            #+#    #+#             */
/*   Updated: 2025/03/03 12:12:59 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*my_getenv(char *name, char **envp)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(name);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
		{
			return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**path_split;
	char	*cmd_path;
	char	*full_path;

	i = -1;
	path_split = ft_split(my_getenv("PATH", envp), ':');
	if (!path_split)
		return (NULL);
	while (path_split[++i])
	{
		cmd_path = ft_strjoin(path_split[i], "/");
		if (ft_strncmp(cmd_path, cmd, ft_strlen(cmd_path)) == 0)
			full_path = ft_strjoin(cmd, "");
		else
			full_path = ft_strjoin(cmd_path, cmd);
		free(cmd_path);
		if (!full_path)
			return (ft_freetab(path_split), NULL);
		if (access(full_path, F_OK | X_OK) == 0)
			return (ft_freetab(path_split), full_path);
		free(full_path);
	}
	ft_error(2);
	return (ft_freetab(path_split), NULL);
}

t_bool	parse_cmd_paths(t_pipex *pipex, int ac, char **envp)
{
	int		i;
	char	**cmdargs_split;

	pipex->cmd_paths = calloc((ac - 2), sizeof(char *));
	if (!pipex->cmd_paths)
		return (false);
	i = -1;
	while (++i < (ac - 3))
	{
		if (!pipex->cmd_args[i][0])
			ft_error(2);
		else
		{
			cmdargs_split = ft_split(pipex->cmd_args[i][0], ' ');
			if (!cmdargs_split)
				return (false);
			pipex->cmd_paths[i] = get_path(cmdargs_split[0], envp);
			ft_freetab(cmdargs_split);
		}
	}
	return (true);
}

t_bool	parse_cmd_args(t_pipex *pipex, int ac, char **av)
{
	int		i;
	char	**cmd_split;

	pipex->cmd_args = calloc((ac - 2), sizeof(char **));
	if (!pipex->cmd_args)
		return (false);
	cmd_split = NULL;
	i = 2;
	while (i < (ac - 1))
	{
		cmd_split = ft_split(av[i], ' ');
		if (!cmd_split)
		{
			free(cmd_split);
			cmd_split = NULL;
		}
		pipex->cmd_args[i - 2] = cmd_split;
		i++;
	}
	return (true);
}

t_bool	parse_args(t_pipex *pipex, int ac, char **av)
{
	if (ac != 5)
		return (ft_exit_err(pipex, 1));
	pipex->in_fd = open(av[1], O_RDONLY, 0644);
	if (pipex->in_fd == -1)
		perror("in_fd");
	pipex->out_fd = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->out_fd == -1)
		perror("out_fd");
	pipex->cmd_count = ac - 3;
	if (pipex->in_fd == -1 || pipex->out_fd == -1)
		return (false);
	return (true);
}
