/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:39:06 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 02:39:15 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process_swap(t_list *pile)
{
	void *tmp;

	if (pile != NULL && pile->next != NULL)
	{
		tmp = pile->content;
		pile->content = pile->next->content;
		pile->next->content = tmp;
	}
}

void	process_push(t_list **receiver, t_list **giver)
{
	t_list *node;

	if ((node = ft_lstpop_node(giver)))
	{
		node->next = *receiver;
		*receiver = node;
	}
}

void	process_rotate(t_list **pile)
{
	t_list *node;

	if ((node = ft_lstpop_node(pile)))
	{
		ft_lstpushback(pile, node);
		node->next = NULL;
	}
}

void	process_reverse_rotate(t_list **pile)
{
	t_list *node;
	if ((node = ft_lstpop_node_back(pile)))
		ft_lstadd(pile, node);
}
