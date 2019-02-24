/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstpop_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 17:44:03 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/24 17:45:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*ft_dlstpop_node(t_dlist **list)
{
	t_dlist *ptr;
	t_dlist *next;

	if (*list != NULL)
	{
		ptr = *list;
		next = (*list)->next;
		(*list)->prev->next = (*list)->next;
		(*list)->next->prev = (*list)->prev;
		if (*list == next)
			*list = NULL;
		else
			*list = next;
		return (ptr);
	}
	return (NULL);
}
