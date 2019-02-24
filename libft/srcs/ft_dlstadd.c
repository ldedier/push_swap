/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 18:21:36 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/24 17:50:25 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (*alst)
	{
		new->next = *alst;
		new->prev = (*alst)->prev;
		(*alst)->prev->next = new;
		(*alst)->prev = new;
	}
	else
	{
		new->next = new;
		new->prev = new;
	}
	*alst = new;
}
