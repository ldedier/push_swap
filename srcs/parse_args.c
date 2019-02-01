/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:12:39 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 03:54:03 by ldedier          ###   ########.fr       */
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

t_item	*get_item(t_list *pile, int value)
{
	t_list *ptr;
	t_item *item;

	ptr = pile;
	while (ptr != NULL)
	{
		item = (t_item *)ptr->content;
		if (item->value == value)
			return (item);
		ptr = ptr->next;
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
	{
	//	ft_dprintf(2, "%s: invalid value\n", str);
		return (print_error());
	}
	if (!ft_is_atoiable(str, &value))
	{
	//	ft_printf("%s: value out of range\n", str);
		return (print_error());
	}
	if ((item = get_item(ps->pile_a, value)))
	{
//		ft_printf("value %d already set (in rank %d)\n", value, item->index);
		return (print_error());
	}
	if (!(new = new_item(value, index++)))
		return (log_error("internal malloc error"));
	if (ft_add_to_list_ptr_back(&ps->pile_a, new, sizeof(t_item)))
		return (log_error("internal malloc error"));
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

int		parse_args_ps(int argc, char **argv, t_push_swap *ps)
{
	int i;

	ps->pile_a = NULL;
	ps->pile_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (parse_arg_ps(argv[i], ps))
		{
			ft_lstdel_value(&ps->pile_a);
			return (1);
		}
		i++;
	}
	return (0);
}
