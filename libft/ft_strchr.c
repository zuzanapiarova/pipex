/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:17:26 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 16:20:52 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char			*res;
	unsigned char	d;

	d = (unsigned char) c;
	res = (char *) s;
	while (*res)
	{
		if (*res == d)
			return ((char *)res);
		res++;
	}
	if (d == '\0')
		return ((char *)res);
	return (0);
}

// int	main(void)
// {
// 	const char *s = "abcdef";
// 	int c = 0;
// 	printf("%s\n", strchr(s, c));
// 	printf("%s\n", ft_strchr(s, c));
// }
