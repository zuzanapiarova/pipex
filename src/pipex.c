/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:47:24 by zpiarova          #+#    #+#             */
/*   Updated: 2024/10/06 22:48:11 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *s)
{
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

// 1. open the file and store its fd into infile variable, before using dup file must be opened
// 2. checks if the file exists and has read permissions
// 3. replace what is at fd 0 with input files fd = set infile to stdin (we want file as input)
// 4. set data->pipefd[1] to be stdout (we want to write output of cmd1 to pipefd[1])
// 5. close other pipe end after using it because excve will not wun aything after itself
void child(t_data *data, char *argv[], char *env[])
{
	int		i;

	close(data->pipefd[0]);
	data->infile = open(argv[1], O_RDONLY, 0777); // 0777 gives rwx permissions to all
	if (data->infile == -1)
		error("Could not open infile.");
	dup2(data->infile, STDIN_FILENO);
	dup2(data->pipefd[1], STDOUT_FILENO);
	close(data->pipefd[1]); //why does this work when we write after closing it?
	data->args1 = ft_split(argv[2], ' '); // this is array, do not forget to free
	data->cmd1 = data->args1[0];
	data->path1 = find_path(data->cmd1, env);
	if (!data->path1)
	{
		i = 0;
		while (data->args1[i])
		{
			free(data->args1[i]);
			i++;
		}
		free(data->args1);
		error("Path to command 1 not found.");
	}
	if (execve(data->path1, data->args1, env) == -1)
		error("Error when executing the command.");
}

// 1. open the file and store its fd into infile variable, file before dup must be opened
// 2. checks if the file exists and has write permissions
// 3. set data->[0] to stdin(0) = pipefd[0] reads from pipefd[1] the output of cmd1
// 4. set outfile to be  stdout(1) = we want to write to it the output of cmd2
// 5. close other pipe end after using it before exec because it will not run anything after it
void parent(t_data *data, char *argv[], char *env[])
{
	int		i;

	close(data->pipefd[1]);
	data->outfile = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (data->outfile == -1)
		error("Could not open or write to outfile.");
	dup2(data->pipefd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->pipefd[0]); // why does this work if we write to pipe after closing it?
	data->args2 = ft_split(argv[3], ' '); // this is array, do not forget to free
	data->cmd2 = data->args2[0];
	data->path2 = find_path(data->cmd2, env);
	if (!data->path2)
	{
		i = 0;
		while (data->args2[i])
		{
			free(data->args2[i]);
			i++;
		}
		free(data->args2);
		error("Path to command 2 not found.");
	}
	if (execve(data->path2, data->args2, env) == -1)
		error("Error when executing the command.");
}

// env stores all environment variables like , we can see them by running env
int	main(int argc, char *argv[], char *env[])
{
	int		pid;
	t_data	data;

	if (argc != 5)
	{
		ft_putstr_fd("Error: bad arguments", 2);
		error("Expects: <infile> <cmd1> <cmd2> <outfile>");
	}
	if (pipe(data.pipefd) == -1)
		error("Error when creating the pipe.");
	pid = fork();
	if (pid == -1)
		error("Error occured when forking.");
	if (pid == 0)
		child(&data, argv, env);
	waitpid(pid, NULL, 0);
	parent(&data, argv, env);
	return (0);
}
