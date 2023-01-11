/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 09:23:23 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/11 15:40:11 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../Libft/libft.h"

// Main Functions
char	*path_finder(char *cmd, char **envp);
void	run_cmd(char *argv, char **envp);
void	err_hndl(char *err);
void	child_process(char **argv, int *fd, char **envp);
void	parent_process(char **argv, int *fd, char **envp);

#endif
