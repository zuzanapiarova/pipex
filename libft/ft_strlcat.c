/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 17:42:03 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/13 21:02:09 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (size == 0)
		return (src_size);
	if (size <= dst_size)
		return (size + src_size);
	while (i < size - dst_size - 1 && src[i])
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}

// int	main (void)
// {
// 	char dest[30];
// 	dest[0] = 'B';
// 	//memset(dest, 'B', 4);
// 	char * src = (char *)"AAAAAAAAA";
// 	printf("result: %ld\n", ft_strlcat(dest, src, 0));
// 	printf("string: %s\n", dest);
// }
