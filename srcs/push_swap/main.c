/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:21:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 21:47:26 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_pivot_index(t_list *list, int start, int end)
{
	(void)list;
	return ((start + end) / 2);
}

int		partition(t_push_swap *ps, int start, int end)
{

}

int		quick_sort_ps(t_push_swap *ps, int start, int end)
{
	(void)ps;
	t_list	*ptr;
	int		val_start;
	int		val_end;
	int		pivot;
	ft_printf("%d\n", start);
	ft_printf("%d\n", end);
	ptr = ft_lstat(ps->pile_a, start);
	val_start = ((t_item *)(ptr->content))->value;
	ptr = ft_lstat(ps->pile_a, end);
	val_end = ((t_item *)(ptr->content))->value;	
	ft_printf("valstart: %d\n", val_start);
	ft_printf("valend: %d\n", val_end);
	if (val_start > val_end)
	{
		ft_printf("olalala\n");
		partition(ps, start, end);
	}
	return (0);
}

int		resolve_push_swap(t_push_swap *ps)
{
	(void)ps;
//	print_push_swap_state(ps, 1);
	quick_sort_ps(ps, 0, ps->nb_values - 1);
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
