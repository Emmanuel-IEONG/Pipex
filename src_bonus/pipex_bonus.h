/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eieong <eieong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 11:03:21 by eieong            #+#    #+#             */
/*   Updated: 2025/02/21 17:18:06 by eieong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include "../libft/ft_printf.h"
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		cmd_count;
	char	**cmd_paths;
	char	***cmd_args;
}				t_pipex;

t_bool	parse_args(t_pipex *pipex, int ac, char **av);
t_bool	parse_cmd_args(t_pipex *pipex, int ac, char **av);
t_bool	parse_cmd_paths(t_pipex *pipex, int ac, char **envp);
char	*my_getenv(char *name, char **envp);
char	*get_path(char *cmd, char **envp);

void	ft_cleanup(t_pipex *pipex);
void	ft_freetabcmd(char **tab, int cmd_count);
void	ft_close_fd(t_pipex *pipex, int pipefd[2]);
void	ft_error(int err);
t_bool	ft_exit_err(t_pipex *pipex, int err);

#endif
