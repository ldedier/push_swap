/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:39:06 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/24 17:50:39 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_swap(t_dlist *pile)
{
	void *tmp;

	if (pile != NULL && pile->next != NULL)
	{
		tmp = pile->content;
		pile->content = pile->next->content;
		pile->next->content = tmp;
	}
}

void	process_push(t_dlist **receiver, t_dlist **giver)
{
	t_dlist *node;

	if ((node = ft_dlstpop_node(giver)))
		ft_dlstadd(receiver, node);
}

void	process_rotate(t_dlist **pile)
{
	if (*pile)
		*pile = (*pile)->next;
}

void	process_reverse_rotate(t_dlist **pile)
{
	if (*pile)
		*pile = (*pile)->prev;
}
