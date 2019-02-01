/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 00:12:16 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 01:09:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list*		ft_lstpop_node_back(t_list **list)
{
	t_list	*ptr;
	t_list	*prev;

	ptr = *list;
	prev = NULL;
	if (ptr)
	{
		while (ptr->next != NULL)
		{
			prev = ptr;
			ptr = ptr->next;
		}
		if (prev == NULL)
		{
			*list = NULL;
			return (ptr);
		}
		else
		{

			prev->next = NULL;
			return (ptr);
		}
	}
	return (NULL);
}
