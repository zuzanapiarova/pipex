/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:03:00 by zpiarova          #+#    #+#             */
/*   Updated: 2024/05/31 21:24:12 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*chars;
	unsigned char	d;

	chars = (unsigned char *) s;
	d = (unsigned char) c;
	if (d > 255)
		d %= 255;
	while (n > 0)
	{
		if (*chars == d)
			return ((void *) chars);
		chars++;
		n--;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char s[] = "abcdef";
// 	unsigned int c = 98;
// 	char *result1 = memchr(s, c, 2);
// 	char *result2 = ft_memchr(s, c, 2);
// 	printf("%s\n", result1);
// 	printf("%s\n", result2);
// }
