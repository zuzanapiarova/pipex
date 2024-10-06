/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:55:33 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 16:11:51 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_index;
	size_t	end_index;
	char	*result;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	while (s1[start_index] && ft_strchr(set, s1[start_index]))
		start_index++;
	end_index = ft_strlen(s1);
	while ((end_index > start_index) && ft_strchr(set, s1[end_index - 1]))
		end_index--;
	result = (char *)malloc((end_index - start_index + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while ((start_index + i) < end_index)
	{
		*(result + i) = *(s1 + (start_index + i));
		i++;
	}
	*(result + i) = '\0';
	return (result);
}

// int main(void)
// {
// 	char *s1 = ".,/,./,./.,abcdef,./..";
// 	char *set = ",./";
// 	printf("result: %s\n", ft_strtrim(s1, set));
// }
