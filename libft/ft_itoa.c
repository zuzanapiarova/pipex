/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:28:17 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 19:34:13 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

size_t	get_size(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n != 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*result;
	long			num;

	size = get_size(n);
	result = (char *)malloc((size + 1) * sizeof(char));
	if (!result)
		return (NULL);
	num = n;
	if (n < 0)
	{
		num *= -1;
	}
	result[size] = '\0';
	while (size > 0)
	{
		result[size - 1] = num % 10 + '0';
		num /= 10;
		size--;
	}
	if (n < 0)
		result[0] = '-';
	return (result);
}

// int main(void)
// {
// 	int n = 183990277;
// 	char *result = ft_itoa(n);
// 	printf("result: %s\n", result);
// 	printf("result: %c\n", result[0]);
// 	printf("result: %c\n", result[1]);
// 	printf("result: %c\n", result[2]);
// 	printf("result: %c\n", result[3]);
// }
