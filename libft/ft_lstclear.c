/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zpiarova <zpiarova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:20:44 by zpiarova          #+#    #+#             */
/*   Updated: 2024/06/14 20:45:51 by zpiarova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current_el;
	t_list	*temp;

	if (!lst || !del)
		return ;
	current_el = *lst;
	while (current_el)
	{
		temp = current_el->next;
		del(current_el->content);
		free(current_el);
		current_el = temp;
	}
	*lst = NULL;
}
