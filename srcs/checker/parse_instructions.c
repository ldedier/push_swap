/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 02:48:36 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 03:48:32 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		parse_double_instruction(char *instruction, t_push_swap *ps)
{
	if (!ft_strcmp(instruction, "ss"))
	{
		process_swap(ps->pile_a);
		process_swap(ps->pile_b);
	}
	else if (!ft_strcmp(instruction, "rr"))
	{
		process_rotate(&ps->pile_a);
		process_rotate(&ps->pile_b);
	}
	else if (!ft_strcmp(instruction, "rrr"))
	{
		process_reverse_rotate(&ps->pile_a);
		process_reverse_rotate(&ps->pile_b);
	}
	else
		return (1);
	return (0);
}

int		parse_instruction(char *raw_instruction, t_push_swap *ps)
{
	char *instruction;

	if (!(instruction = ft_strtrim(raw_instruction)))
		return (1);
	if (!ft_strcmp(instruction, "sa"))
		process_swap(ps->pile_a);
	else if (!ft_strcmp(instruction, "sb"))
		process_swap(ps->pile_b);
	else if (!ft_strcmp(instruction, "pa"))
		process_push(&ps->pile_a, &ps->pile_b);
	else if (!ft_strcmp(instruction, "pb"))
		process_push(&ps->pile_b, &ps->pile_a);
	else if (!ft_strcmp(instruction, "ra"))
		process_rotate(&ps->pile_a);
	else if (!ft_strcmp(instruction, "rb"))
		process_rotate(&ps->pile_b);
	else if (!ft_strcmp(instruction, "rra"))
		process_reverse_rotate(&ps->pile_a);
	else if (!ft_strcmp(instruction, "rrb"))
		process_reverse_rotate(&ps->pile_b);
	else if (parse_double_instruction(instruction, ps))
		return (ft_free_turn(instruction, 1));
	return (ft_free_turn(instruction, 0));
}

int		parse_instructions(t_checker *checker)
{
	int			ret;
	char		*line;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (parse_instruction(line, &checker->ps))
		{
			print_error();
			free(line);
			free_all(checker);
			return (1);
		}
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

