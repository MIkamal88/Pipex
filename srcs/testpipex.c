/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 08:32:56 by mshehata          #+#    #+#             */
/*   Updated: 2023/01/09 15:43:50 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex	file1	cmd1	cmd2	file2
//	argv[0]	argv[1]	argv[2]	argv[3]	argv[4]
// fd[0] = read
// fd[1] = write
//execve(pathname, argv, envp)
// void	child_process(char **argv, int *fd, char **envp)
// {
// 	int		filein;
// 	char	*cmd_path;

// 	filein = open(argv[1], O_RDONLY);
// 	cmd_path = path_finder(argv[2], envp);
// 	if (filein == -1)
// 		printf("filein = -1");
// 	printf("%s in cmd ", cmd_path);
// 	dup2(fd[1], STDOUT_FILENO);
// 	// dup2(filein, STDIN_FILENO);
// 	close(fd[0]);
// 	close(fd[1]);
// 	execve(cmd_path, &cmd_path, envp);
// }

// void	parent_process(char **argv, int *fd, char **envp)
// {
// 	int		fileout;
// 	char	*cmd_path;

// 	fileout = open(argv[4], O_WRONLY);
// 	cmd_path = path_finder(argv[3], envp);
// 	if (fileout == -1)
// 		printf("fileout = -1");
// 	printf("%s out ", cmd_path);
// 	dup2(fd[0], STDIN_FILENO);
// 	// dup2(fileout, STDOUT_FILENO);
// 	close(fd[1]);
// 	close(fd[0]);
// 	execve(cmd_path, &cmd_path, envp);
// }

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	char *cmd = "/usr/bin/ls";
	char **args = malloc(sizeof(char *) * 2);
	int infile = open("infile", O_WRONLY | O_RDONLY);
	int outfile = open("outfile", O_WRONLY);
	args[0] = cmd;
	args[1] = NULL;

	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDOUT_FILENO);
		close(infile);
		close(outfile);
		execve(cmd, args, NULL);
		exit(0);
	}
	char *out_cmd = "/usr/bin/wc";
	char **args_out = malloc(sizeof(char *) *2);

	args_out[0] = out_cmd;
	args_out[1] = NULL;
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(infile);
		close(outfile);
		execve(out_cmd, args_out, NULL);
		exit(0);
	}
	exit(0);
	// pid1 = fork();
	// if (pid1 == -1)
	// {
	// 	printf("Error");
	// 	return (1);
	// }
	// if (pid1 == 0)
	// 	child_process(argv, fd, envp);
	// waitpid(pid1, NULL, 0);
	// parent_process(argv, fd, envp);
	return (0);
}
