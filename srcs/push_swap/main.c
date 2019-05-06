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

int		process_populate_path(t_item *prev_item,
			t_item *next_item, int rank, t_path *path)
{
	if (rank + 1 == prev_item->rank)
	{
		path->has_second = 1;
		path->second_dir = - path->dir;
	}
	else if (rank + 1 == next_item->rank)
	{
		path->has_second = 1;
		path->second_dir = path->dir;
	}
	if (rank == prev_item->rank)
	{
		path->dir = - path->dir;
		if (path->has_second && path->second_dir > 0)
			path->has_second = 0;
		return (1);
	}
	else if (rank == next_item->rank)
	{
		if (path->has_second && path->second_dir < 0)
			path->has_second = 0;
		return (1);
	}
	return (0);
}

void	populate_path(t_push_swap *ps, t_dlist *pile, int rank, t_path *path)
{
	t_dlist *prev_ptr;
	t_dlist *next_ptr;
	int		first;

	prev_ptr = pile;
	next_ptr = pile;
	path->has_second = 0;
	path->dir = 0;
	while (1)
	{
		(void)ps;
//		if(rank == ((t_item *)(prev_ptr->content))->rank)
//			ft_printf(BLUE"OUAI"EOC);

//		ft_printf("RANK: %d %d\n", rank, ((t_item *)(prev_ptr->content))->rank);
		if (process_populate_path((t_item *)prev_ptr->content,
			(t_item *)next_ptr->content, rank, path))
			return ;
		first = 0;
		prev_ptr = prev_ptr->prev;
		next_ptr = next_ptr->next;
		path->dir++;
	}
}

void	process_transfert(t_push_swap *ps, int *rank)
{
	t_path	path;
	int		i;

	populate_path(ps,ps->pile_a, *rank, &path);
	*rank += (path.has_second ? 2 : 1);
	i = 0;
	if (path.dir < 0)
	{
		if (path.has_second)
		{
			while (i > path.second_dir)
			{
				process_instruction("rra", ps, 1);
				i--;
			}
			process_instruction("pb", ps, 1);
		}
		while (i > path.dir)
		{
			process_instruction("rra", ps, 1);
			i--;
		}
		process_instruction("pb", ps, 1);
	}
	else
	{
		if (path.has_second)
		{
			while (i < path.second_dir)
			{
				process_instruction("ra", ps, 1);
				i++;
			}
			process_instruction("pb", ps, 1);
			i++;
		}
		while (i < path.dir)
		{
			process_instruction("ra", ps, 1);
			i++;
		}
		process_instruction("pb", ps, 1);
	}
	if (path.has_second)
		process_instruction("sb", ps, 1);
}

int		resolve_push_swap(t_push_swap *ps)
{
	int rank;

	rank = 1;
	while (ps->pile_a)
		process_transfert(ps, &rank);
	while (ps->pile_b)
		process_instruction("pa", ps, 1);
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
