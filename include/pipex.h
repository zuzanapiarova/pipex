/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 09:54:17 by zpiarova          #+#    #+#             */
/*   Updated: 2024/10/06 17:43:15 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h> // read
#include <unistd.h> // access
#include <stdlib.h> // exit
#include <fcntl.h> // macros like R_ONLY
#include <sys/wait.h> //wait, waitpid
#include "../libft/libft.h" // libft

typedef struct	s_data
{
	int	infile;
	int	outfile;
	char	*cmd1;
	char	*cmd2;
	char	*path1;
	char	*path2;
	char	**args1;
	char	**args2;
}				t_data;

char	*find_path(char *cmd, char **envp);

#endif
