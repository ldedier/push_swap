/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:21:31 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 03:48:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void __attribute__((destructor)) end();

void    end(void) //permet de mieux checker les leaks !
{
//		ft_printf("destructor loop\n");
//			while(1);
}

void	free_all(t_checker *checker)
{
	free_push_swap(&checker->ps);
}

int		print_result(t_checker *checker)
{
	if (is_solved_push_swap(&(checker->ps)))
	{
		ft_printf("OK\n");
		return (0);
	}
	else
	{
		ft_printf("KO\n");
		return (1);
	}
}

int		main(int argc, char **argv)
{
	t_checker	checker;
	int			ret;

	if (argc == 1)
		return (print_usage(argv[0]));
	else if (parse_args_ps(argc, argv, &(checker.ps)))
		return (1);
	if (parse_instructions(&checker))
		return (1);
	ret = print_result(&checker);
	free_all(&checker);
	return (ret);
}
