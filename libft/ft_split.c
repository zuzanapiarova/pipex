/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:14:38 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 19:58:29 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t	count_elements(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] && i < ft_strlen(s))
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			i++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
		i++;
	}
	return (count);
}

// void	free_array(size_t count, char **array)
// {
// 	while (count > 0)
// 	{
// 		count--;
// 		free(*(array + count));
// 	}
// 	free(array);
// }

char	**ft_split(char const *s, char c)
{
	t_vars	vars;

	vars.i = 0;
	vars.j = 0;
	vars.arr = (char **)malloc((count_elements(s, c) + 1) * sizeof(char *));
	if (!vars.arr)
		return (NULL);
	while (vars.j < count_elements(s, c))
	{
		while (s[vars.i] == c)
			vars.i++;
		if (s[vars.i] != c && s[vars.i] != '\0')
			vars.start_i = vars.i;
		while (s[vars.i + 1] != c && s[vars.i + 1] != '\0')
			vars.i++;
		vars.arr[vars.j] = ft_substr(s, vars.start_i, vars.i - vars.start_i
				+ 1);
		vars.i++;
		vars.j++;
	}
	vars.arr[vars.j] = NULL;
	return (vars.arr);
}

// int main(void)
// {
// 	char *s = ",1.,2..,3...,4....,5.....,,,,l,";
// 	char c = ',';
// 	char **arr;
// 	arr = ft_split(s, c);
// 	printf("%s\n", arr[0]);
// 	printf("%s\n", arr[1]);
// 	printf("%s\n", arr[2]);
// 	printf("%s\n", arr[3]);
// 	printf("%s\n", arr[4]);
// 	printf("%s\n", arr[5]);
// 	printf("%s\n", arr[6]);
// }
