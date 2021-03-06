/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 03:05:48 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/24 17:36:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_push_swap(t_push_swap *ps)
{
	ft_dlstdel_value(&ps->pile_a);
	ft_dlstdel_value(&ps->pile_b);
}
