/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 17:18:51 by zpiarova          #+#    #+#             */
/*   Updated: 2024/10/08 18:17:34 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// 1. find environment variable starting with PATH
// 2. path ENV consists of all possible paths where commands are located
//    on the machine, separated by colon :
// 3. separate this entire string of paths into array called paths
// 4. for each of these paths:
//   1. append "\" to the end of the path
//   2. append the command (file) at the end of the path
//   3. cheeck if file at this path exists with access()
//   4. free all allocated memory properly 
char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*path_without_cmd;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path_without_cmd = ft_strjoin(paths[i], "/");
		path = ft_strjoin(path_without_cmd, cmd);
		free(path_without_cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (NULL);
}
