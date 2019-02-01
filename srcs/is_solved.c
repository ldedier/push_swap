/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_solved.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 03:02:21 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 03:02:57 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted_pile(t_list *pile)
{
	t_list	*ptr;
	t_item	*item;
	t_item	*previous_item;

	ptr = pile;
	previous_item = NULL;
	while (ptr != NULL)
	{
		item = (t_item *)ptr->content;
		if (previous_item && previous_item->value > item->value)
			return (0);
		previous_item = item;
		ptr = ptr->next;
	}
	return (1);
}

int		is_solved_push_swap(t_push_swap *ps)
{
	return (ps->pile_b == NULL && is_sorted_pile(ps->pile_a));
}
