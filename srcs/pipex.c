/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 08:32:56 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/07 10:57:49 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex	file1	cmd1	cmd2	file2
//	argv[0]	argv[1]	argv[2]	argv[3]	argv[4]
// fd[0] = read
// fd[1] = write
//execve(pathname, argv, envp)
void	child_process(char **argv, int *fd, char **envp)
{
	int		filein;
	char	*path;

	filein = open(argv[1], O_RDONLY);
	path = path_finder(argv[2], envp);
	if (filein == -1)
		printf("filein = -1");
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execve(path, argv[2], envp);
}

void	parent_process(char **argv, int *fd, char **envp)
{
	int		fileout;
	char	*path;

	fileout = open(argv[4], O_WRONLY);
	path = path_finder(argv[3], envp);
	if (fileout == -1)
		printf("fileout = -1");
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execve(path, argv[4], envp);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	int		fd[2];

	if (argc != 5)
		printf("Error");
	if (pipe(fd) == -1)
	{
		printf("Error");
		return (1);
	}
	pid1 = fork();
	if (pid1 == -1)
	{
		printf("Error");
		return (1);
	}
	if (pid1 == 0)
		child_process(argv, fd, envp);
	waitpid(pid1, NULL, 0);
	parent_process(argv, fd, envp);
	return (0);
}
