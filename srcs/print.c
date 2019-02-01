/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:26:41 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 02:42:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		print_usage(char *progname)
{
	ft_printf("usage: %s $ARG\n", progname);
	return (1);
}

int		log_error(char *str)
{
	ft_dprintf(2, "%s\n", str);
	return (1);
}

void	print_pile(t_list *pile)
{
	t_list *ptr;
	t_item *item;
	int i;

	i = 1;
	ptr = pile;
	while (ptr != NULL)
	{
		item = (t_item *)ptr->content;
		ft_printf("slot #%d: %d\n", i++, item->value);
		ptr = ptr->next;
	}
	if (i == 1)
		ft_printf("empty !\n");
}

void	print_push_swap_state(t_push_swap *ps)
{
	ft_printf(RED"\nPile A:\n\n");
	print_pile(ps->pile_a);
	ft_printf(EOC);
	ft_printf(BLUE"\nPile B:\n\n");
	print_pile(ps->pile_b);
	ft_printf(EOC"\n");
}

int		print_error(void)
{
	ft_dprintf(2, "Error\n");
	return (1);
}
