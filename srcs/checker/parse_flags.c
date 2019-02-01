/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 05:44:06 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 05:52:51 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		parse_flag(char *str, t_checker *checker)
{
	if (!ft_strcmp(str, "-v"))
		checker->verbosed = 1;
	else if (!ft_strcmp(str, "-c"))
		checker->colored = 1;
	else if (!ft_strcmp(str, "-i"))
		checker->show_nb_instructions = 1;
	else if (!ft_strcmp(str, "-V"))
		checker->visu.active = 1;
	else
		return (0);
	return (1);
}

void	parse_flags(int argc, char **argv, int *index, t_checker *checker)
{
	while (*index < argc && parse_flag(argv[*index], checker))
		*index += 1;
}
