/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:09:04 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 16:19:30 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*chars;
	unsigned char	d;
	size_t			i;

	chars = (unsigned char *) s;
	if (c >= 256)
		c -= 256;
	d = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		chars[i] = d;
		i++;
	}
	return (s);
}

// int	main(void)
// {
// 	char			s[50] = "abcdef";
// 	unsigned char	c = 97;
// 	size_t			n = 4;

// 	char	*result1 = ft_memset(s, c, n);
// 	printf("%s\n", result1);
// 	char	*result2 = memset(s, c, n);
// 	printf("%s\n", result2);
// }
