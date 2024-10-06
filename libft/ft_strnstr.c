/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 19:46:57 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 19:07:34 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;
	size_t	little_length;
	size_t	big_length;

	if ((!big || !little) && !len)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	little_length = ft_strlen(little);
	big_length = ft_strlen(big);
	if (big_length < little_length || len < little_length)
		return (0);
	if (big_length > len)
		size = len;
	else
		size = big_length;
	while (size >= little_length)
	{
		if (ft_strncmp(big, little, little_length) == 0)
			return (((char *)(big)));
		big++;
		size--;
	}
	return (0);
}

// int	main(void)
// {
// 	char *little = "lo";
// 	char *big = "hello world";
// 	//char *big = ((void*)0);
// 	printf("%s", ft_strnstr(big, little, 6));
// }
