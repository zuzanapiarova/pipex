/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:37:44 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/13 20:35:58 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	char	*chardest;
	char	*charsrc;

	i = 0;
	chardest = (char *) dest;
	charsrc = (char *) src;
	if (!dest && !src)
		return (NULL);
	while (n > 0)
	{
		chardest[i] = charsrc[i];
		i++;
		n--;
	}
	return ((void *) dest);
}

// int	main(void)
// {
// 	char dest1[] = "AAAAAAA";
// 	char dest2[] = "AAAAAAA";
// 	char src1[] = {0, 0};
// 	char src2[] = {0, 0};
// 	ft_memcpy(dest1, src1, 2);
// 	memcpy(dest2, src2, 2);
// 	printf("%c\n", dest1[1]);
// 	printf("%c\n", dest2[1]);
// }
