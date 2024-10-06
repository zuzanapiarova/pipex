/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:47:24 by zpiarova          #+#    #+#             */
/*   Updated: 2024/10/06 17:42:11 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
//creating pipe for command "cat infile | grep Lausanne"
// < file1 "cmd1 args1" | "cmd2 args2" > outfile

int	check_command(char *path)
{
	if (!access(path, F_OK))
	{
		printf("This command does not exist.");
		return (0);
	}
	else if (!access(path, X_OK))
	{
		printf("Do not have execute permissions for this file.");
		return (0);
	}
	return (1);
}
// 1. pipe
// 2. fork
// 3. set proper pipes end to the processes
//                           ______
// outfile <-- parent <-- RD()_____)WR <--child <-- infile
// parent reads from RD (output) end
// child writes to WR (input) end
// pipefd[1] is for child process, and pipefd[0] is for parent process:
// since for something to be read, it must be written first
// child must write first, parent has ability to wait for it so it must go second to read
// cmd1 goes first and reads from infile so it will be executed by the child
// cmd2 depends on output of cmd1 and writes to outfile so it is executed by the parent
// we forked process after piping so both child and parent have:
// pipefd[0]
// pipefd[1]
int	main(int argc, char *argv[], char *env[])
{
	int		pipefd[2]; //pipefd[0] is RD, pipefd[1] is WR
	int		pid;
	t_data	data;
	int		i;

	if (argc != 5)
	{
		ft_putstr_fd("Error: bad arguments", 2);
		ft_putstr_fd("Expects: <infile> <cmd1> <cmd2> <outfile>", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(pipefd) == -1)
	{
		ft_putstr_fd("Error occured when opening the pipe.", 2);
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error occured when forking.", 2);
		exit(EXIT_FAILURE);
	}
	if (pid == 0) // CHILD = we know child has pid 0
	{
		close(pipefd[0]);
		// open the file and store its fd into infile variable, file before dup must be opened
		data.infile = open(argv[1], O_RDONLY, 0777); // 0777 gives rwx permissions to all
		// checks if the file exists aand has read permissions
		if (data.infile == -1)
		{
			ft_putstr_fd("Could not open infile.", 2);
			exit(EXIT_FAILURE);
		}
		// replace what is at fd 0 with input files fd = set infile to stdin (we want file as input)
		dup2(data.infile, STDIN_FILENO);
		// set pipefd[1] to be stdout (we want to write output of cmd1 to pipefd[1])
		dup2(pipefd[1], STDOUT_FILENO);
		// close other pipe end after using it because excve will not wun aything after itself
		close(pipefd[1]); //why does this work when we write after closing it?
		// perform action
			// char x[10];
			// read(0, &x, 10);
			// printf("%s", x);
			data.args1 = ft_split(argv[2], ' '); // this is array, do not forget to free
			data.cmd1 = data.args1[0];
			data.path1 = find_path(data.cmd1, env);
			if (!data.path1)
			{
				i = 0;
				while (data.args1[i])
				{
					free(data.args1[i]);
					i++;
				}
				free(data.args1);
				ft_putstr_fd("Path to command file not found.", 2);
				exit(EXIT_FAILURE);
			}
			if (execve(data.path1, data.args1, env) == -1)
			{
				ft_putstr_fd("Could not find command 1 or other error when executing the command.", 2);
				exit(EXIT_FAILURE);
			}
	}
	else // PARENT
	{
		waitpid(pid, NULL, 0);
		close(pipefd[1]);
		// open the file and store its fd into infile variable, file before dup must be opened
		data.outfile = open(argv[4], O_WRONLY | O_CREAT, 0777);
		// checks if the file exists and has write permissions
		if (data.outfile == -1)
		{
			ft_putstr_fd("Could not open or write to outfile.", 2);
			exit(EXIT_FAILURE);
		}
		// set pipefd[0] to stdin(0) = pipefd[0] reads from pipefd[1] the output of cmd1
		dup2(pipefd[0], STDIN_FILENO);
		// set outfile to be  stdout(1) = we want to write to it the output of cmd2
		dup2(data.outfile, STDOUT_FILENO);
		// close other pipe end after using it before exec because it will not run anything after it
		close(pipefd[0]); // why does this work if we write to pipe after closing it?
		// perform action
			// char y[10];
			// read(0, &y, 10);
			// printf("%s", y);
			//write(1, y, 10);
			data.args2 = ft_split(argv[3], ' '); // this is array, do not forget to free
			data.cmd2 = data.args2[0];
			data.path2 = find_path(data.cmd2, env);
			if (!data.path2)
			{
				i = 0;
				while (data.args2[i])
				{
					free(data.args2[i]);
					i++;
				}
				free(data.args2);
				ft_putstr_fd("Path to command file not found.", 2);
				exit(EXIT_FAILURE);
			}
			if (execve(data.path2, data.args2, env) == -1)
			{
				ft_putstr_fd("Eerror when executing the command.", 2);
				exit(EXIT_FAILURE);
			}
	}
	return (0);
}

// setting up fork and pipe - only need to add commands now
// int hi(/* int argc, char *argv[] */void)
// {
// 	int fd[2];
// 	int pid;

// 	if (pipe(fd) == -1)
// 	{
// 		printf("Error when piping.");
// 		return (EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		close (fd[0]);
// 		int x;
// 		printf("Enter a number: ");
// 		scanf("%d", &x);
// 		write(fd[1], &x, sizeof(int));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		close(fd[1]);
// 		int y;
// 		read(fd[0], &y, sizeof(int));
// 		close(fd[0]);
// 		printf("Var from pipe from child: %d\n", y);
// 	}
// 	return (0);
// }
