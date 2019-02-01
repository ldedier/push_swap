/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:21:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 05:52:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void __attribute__((destructor)) end();

void	end(void)
{
//	ft_printf("destructor loop\n");
//	while(1);
}

void	free_all(t_checker *checker)
{
	free_push_swap(&checker->ps);
}

int		print_result(t_checker *checker)
{
	if (is_solved_push_swap(&(checker->ps)))
	{
		if (checker->show_nb_instructions)
		{
			ft_printf("OK in %s%d instruction%s%s to sort %s%d value%s%s\n",
				GREEN, checker->nb_instructions,
					checker->nb_instructions == 1 ? "" : "s", EOC, RED,
						checker->ps.nb_values,
							checker->ps.nb_values == 1 ? "" : "s",
								EOC);
		}
		else
			ft_printf("OK\n");
		return (0);
	}
	else
	{
		ft_printf("KO\n");
		return (1);
	}
}

void	init_checker(t_checker *checker)
{
	checker->verbosed = 0;
	checker->colored = 0;
	checker->show_nb_instructions = 0;
	checker->visu.active = 0;
}

int		main(int argc, char **argv)
{
	t_checker	checker;
	int			ret;
	int			index;

	if (argc == 1)
		return (print_usage(argv[0]));
	index = 1;
	parse_flags(argc, argv, &index, &checker);
	if (parse_args_ps(index, argc, argv, &(checker.ps)))
		return (1);
	if (checker.verbosed)
		print_push_swap_state(&(checker.ps), checker.colored);
	if (parse_instructions(&checker))
		return (1);
	ret = print_result(&checker);
	free_all(&checker);
	return (ret);
}
