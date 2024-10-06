/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:59:19 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/13 21:27:41 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*chars;

	i = 0;
	chars = (unsigned char *) s;
	while (i < n)
	{
		chars[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char s1[20] = "abcdef";
// 	printf("%c\n", s1[2]);
// 	bzero(s1, 3);
// 	printf("%c\n", s1[2]);

// 	char s2[20] = "abcdef";
// 	printf("%c\n", s2[2]);
// 	ft_bzero(s2, 3);
// 	printf("%c\n", s2[2]);
// }
