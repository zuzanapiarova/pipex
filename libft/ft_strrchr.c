/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:32:51 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/13 21:04:53 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char			*result;
	char			*chars;
	unsigned char	d;

	result = NULL;
	chars = (char *) s;
	d = (unsigned char) c;
	if (d == 0)
		return (chars + ft_strlen(chars));
	if (d > 255)
		d %= 255;
	while (*chars)
	{
		if (*chars == d)
			result = chars;
		chars++;
	}
	return (result);
}
// int	main(void)
// {
// 	const char	*s1 = "abcdeadf";
// 	const char	*s2 = "abcdeadf";
// 	int c = 353;
// 	printf("%s\n", strrchr(s1, c));
// 	printf("%s\n", ft_strrchr(s2, c));
// }
