/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:12:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/24 17:35:13 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*new_item(int value, int index)
{
	t_item *res;

	if (!(res = (t_item *)malloc(sizeof(t_item))))
		return (NULL);
	res->value = value;
	res->index = index;
	return (res);
}

t_item	*get_item(t_dlist *pile, int value)
{
	t_dlist *ptr;
	t_item *item;
	int		first;

	first = 1;
	ptr = pile;
	while ((ptr != pile && ptr != NULL) || (first && ptr != NULL))
	{
		item = (t_item *)ptr->content;
		if (item->value == value)
			return (item);
		ptr = ptr->next;
		first = 0;
	}
	return (NULL);
}

int		add_item_to_ps(char *str, t_push_swap *ps)
{
	static int	index = 1;
	int			value;
	t_item		*new;
	t_item		*item;

	if (!ft_isdigit_str(str))
		return (print_error());
	if (!ft_is_atoiable(str, &value))
		return (print_error());
	if ((item = get_item(ps->pile_a, value)))
		return (print_error());
	if (!(new = new_item(value, index++)))
		return (log_error("internal malloc error"));
	if (ft_add_to_dlist_ptr_back(&ps->pile_a, new, sizeof(t_item)))
		return (log_error("internal malloc error"));
	ps->nb_values++;
	return (0);
}

int		parse_arg_ps(char *str, t_push_swap *ps)
{
	char	**split;
	int		i;

	if (!(split = ft_split_whitespace(str)))
		return (1);
	i = 0;
	while (split[i])
	{
		if (add_item_to_ps(split[i], ps))
		{
			ft_free_split(split);
			return (1);
		}
		i++;
	}
	ft_free_split(split);
	return (0);
}

void	process_add_ranks(t_dlist *dlist, t_item *item)
{
	int		first;
	t_dlist	*ptr;
	t_item	*compare;

	ptr = dlist;
	first = 1;
	while ((ptr != dlist && ptr != NULL) || (first && ptr != NULL))
	{
		compare = (t_item *)ptr->content;
		if (item->value >= compare->value)
			item->rank++;
		ptr = ptr->next;
		first = 0;
	}
}

void	add_ranks(t_dlist *dlist)
{
	int first;
	t_dlist *ptr;
	t_item *item;

	first = 1;
	ptr = dlist;
	while ((ptr != dlist && ptr != NULL) || (first && ptr != NULL))
	{
		item = (t_item *)ptr->content;
		item->rank = 0;
		process_add_ranks(dlist, item);
		ptr = ptr->next;
		first = 0;
	}
}

int		parse_args_ps(int i, int argc, char **argv, t_push_swap *ps)
{
	ps->pile_a = NULL;
	ps->pile_b = NULL;
	ps->nb_values = 0;
	if (i >= argc)
	{
		print_error();
		return (1);
	}
	while (i < argc)
	{
		if (parse_arg_ps(argv[i], ps))
		{
			ft_dlstdel_value(&ps->pile_a);
			return (1);
		}
		i++;
	}
	add_ranks(ps->pile_a);
	return (0);
}
