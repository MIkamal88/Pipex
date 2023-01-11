/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:11:02 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/11 12:48:06 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex	infile	cmd1	cmd2	outfile
//	argv[0]	argv[1]	argv[2]	argv[3]	argv[4]
// fd[0] = read
// fd[1] = write
//execve(pathname, argv, envp)
void	child_process(char **argv, int *fd, char **envp)
{
	int	filein;

	filein = open(argv[1], O_RDONLY);
	if (filein == -1)
		err_hndl("\033[31mError parsing Infile FD");
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	run_cmd(argv[2], envp);
}

void	parent_process(char **argv, int *fd, char **envp)
{
	int	fileout;

	fileout = open(argv[4], O_WRONLY);
	if (fileout == -1)
		err_hndl("\033[31mError parsing Outfile FD");
	dup2(fileout, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	run_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	int		fd[2];

	if (argc != 5)
		err_hndl("\033[31mInvalid Arguments");
	if (pipe(fd) == -1)
		err_hndl("\033[31mPipe failed");
	pid1 = fork();
	if (pid1 == -1)
		err_hndl("\033[31mForking failed");
	if (pid1 == 0)
		child_process(argv, fd, envp);
	waitpid(pid1, NULL, 0);
	parent_process(argv, fd, envp);
	return (0);
}
