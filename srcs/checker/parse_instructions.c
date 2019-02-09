/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:48:36 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/09 20:13:34 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		parse_instructions(t_checker *checker)
{
	int			ret;
	char		*line;

	checker->nb_instructions = 0;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (process_instruction(line, &checker->ps, 0))
		{
			print_error();
			free(line);
			free_all(checker);
			return (1);
		}
		if (checker->verbosed)
			print_push_swap_state(&(checker->ps), checker->colored);
		checker->nb_instructions++;
		free(line);
	}
	if (ret == -1)
	{
		free_all(checker);
		return (1);
	}
	free(line);
	return (0);
}
