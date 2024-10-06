/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:24:01 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/15 21:02:12 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//doda+t ochranu ored overflow
void	*ft_calloc(size_t nelem, size_t elsize)
{
	unsigned char	*result;
	int				size;
	int				i;

	i = 0;
	if (nelem == 0 || elsize == 0)
		return (malloc(1));
	size = nelem * elsize;
	result = (unsigned char *)malloc(size);
	if (!result)
		return (NULL);
	while (i < size)
	{
		result[i] = 0;
		i++;
	}
	return ((char *)result);
}
