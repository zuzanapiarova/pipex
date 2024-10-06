/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:03:57 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/13 20:36:32 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	src_cpy(char *pdest, char *psrc, size_t n)
{
	size_t	i;

	i = 0;
	if (pdest > psrc)
	{
		while (n != 0)
		{
			n--;
			pdest[n] = psrc[n];
		}
	}
	else
	{
		while (i < n)
		{
			pdest[i] = psrc[i];
			i++;
		}
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*pdest;
	char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (char *) dest;
	psrc = (char *) src;
	src_cpy(pdest, psrc, n);
	return ((void *) dest);
}

// int	main(void)
// {
// 	char dest1[] = "abcdef";
// 	char dest2[] = "abcdef";
// 	char src1[] = {0, 0};
// 	char src2[] = {0, 0};
// 	printf("%c, %p, %p\n", dest1[1], &dest1[1], &dest1[3]);
// 	printf("%c, %p, %p\n", dest2[1], &dest2[1], &dest2[3]);
// 	ft_memmove(dest1, dest1 + 2, 2);
// 	memmove(dest2, dest2 + 2, 2);
// 	printf("%c, %p, %p\n", dest1[1], &dest1[1], &dest1[3]);
// 	printf("%c, %p, %p\n", dest2[1], &dest2[1], &dest2[3]);
// }
