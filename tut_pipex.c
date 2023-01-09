/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshehata <mshehata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 19:00:47 by mshehata          #+#    #+#             */
/*   Updated: 2022/12/25 19:00:47 by mshehata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	id;
	int	fd[2];
	// fd[0] = read
	// fd[1] = write

	if (pipe(fd) == -1)
	{
		printf("An error occured opening the pipe.\n");
		return (1);
	}
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int	x;
		printf("Input a number: ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		int	y;
		read(fd[0], &y, sizeof(int));
		printf("Got from Child process: %d\n", y);
		close(fd[0]);
	}
	return (0);
}

