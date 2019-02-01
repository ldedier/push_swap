/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:21:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 05:56:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		resolve_push_swap(t_push_swap *ps)
{
	(void)ps;
	print_push_swap_state(ps, 1);
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
