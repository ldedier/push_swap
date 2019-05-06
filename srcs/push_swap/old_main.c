/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:21:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/24 17:33:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
int		get_pivot_index(t_dlist *dlist, int start, int end)
{
	(void)list;
	return ((start + end) / 2);
}

int		get_value_index(t_dlist *pile, int value)
{
	int		i;
	t_list	*ptr;

	ptr = pile;
	i = 0;
	while (ptr != NULL)
	{
		if (((t_item *)(ptr->content))->value == value)
			return (i);
		ptr = ptr->next;
		i++;
	}
	return (-1);
}

int		is_sorted_around_pivot(t_push_swap *ps, int start, int end)
{
	t_list	*ptr;
	int		pivot;
	int		value;
	int		i;

	(void)start;
	(void)end;
//	ft_printf("%d %d\n", start, end);
//	ft_printf("%d %d\n", ft_lstlength(ps->pile_a), start);
	ptr = ft_lstat(ps->pile_a, start);
	pivot = ((t_item *)(ptr->content))->value;
	i = start + 1;
	ptr = ptr->next;
	while (i <= end)
	{
		value = ((t_item *)(ptr->content))->value;
//		ft_printf("%d, %d\n", value, pivot);
		if (value < pivot)
			return (0);
		i++;
		ptr = ptr->next;
	}
	return (1);
}

int		partition(t_push_swap *ps, int start, int end)
{
	int		pivot;
	int		i;
	t_list	*ptr;

	if (!is_sorted_around_pivot(ps, start, end))
	{
		//	ft_printf("start: %d\n", start);
		//	ft_printf("end: %d\n", end);
		i = 0;
		while (i++ < start)
		{
			//ft_printf("WOOLIT %d\n", start);
			process_instruction("ra", ps, 1);
		}
		//	print_push_swap_state(ps, 1);
		i = -1;
		while (++i < end - start + 1)
			process_instruction("pb", ps, 1);
		//	print_push_swap_state(ps, 1);
		ptr = ft_lstat(ps->pile_b, i - 1);
		pivot = ((t_item *)(ptr->content))->value;
		while (i--)
		{
			ptr = ps->pile_b;
			if (((t_item *)(ptr->content))->value > pivot)
				process_instruction("pa", ps, 1);
			else if (((t_item *)(ptr->content))->value < pivot)
				process_instruction("rb", ps, 1);
		}
//		ft_printf("PIVOT: %d\n", pivot);
//		print_push_swap_state(ps, 1);
		while (ps->pile_b)
			process_instruction("pa", ps, 1);
	//		print_push_swap_state(ps, 1);
		i = 0;
		while (i++ < start)
			process_instruction("rra", ps, 1);
	//		print_push_swap_state(ps, 1);
	//		ft_printf(GREEN"SORTED AROUND %d\n"EOC, pivot);
		return (get_value_index(ps->pile_a, pivot));
	}
	else
		return (start);
}

int		quick_sort_ps(t_push_swap *ps, int start, int end)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(ps, start, end);
//		ft_printf("PIVOT INDEX: %d\n", pivot_index);
		quick_sort_ps(ps, start, pivot_index - 1);
		quick_sort_ps(ps, pivot_index + 1, end);
	}
	return (0);
}
*/
int		resolve_push_swap(t_push_swap *ps)
{
	(void)ps;
//	print_push_swap_state(ps, 1);
//	quick_sort_ps(ps, 0, ps->nb_values - 1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_push_swap ps;
	int			ret;

	if (argc == 1)
		return (print_usage(argv[0]));
	else if (parse_args_ps(1, argc, argv, &ps))
		return (1);
	ret = resolve_push_swap(&ps);
	free_push_swap(&ps);
	return (ret);
}
