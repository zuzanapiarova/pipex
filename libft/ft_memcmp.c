/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zuzanapiarova <zuzanapiarova@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 21:26:03 by zpiarova          #+#    #+#             */
/*   Updated: 2024/10/06 20:58:39 by zuzanapiaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chars1;
	unsigned char	*chars2;

	chars1 = (unsigned char *) s1;
	chars2 = (unsigned char *) s2;
	while (n > 0)
	{
		if (*chars1 != *chars2)
			return (*chars1 - *chars2);
		n--;
		chars1++;
		chars2++;
	}
	return (0);
}

// int	main(void)
// {
// 	char s11[] = "abcdef";
// 	char s12[] = "bbcdef";
// 	char s21[] = "abcdef";
// 	char s22[] = "bbcdef";
// 	printf("%d\n", memcmp(s11, s12, 2));
// 	printf("%d\n", ft_memcmp(s21, s22, 2));
// }
