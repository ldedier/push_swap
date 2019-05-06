/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_instruction.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 20:08:16 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/09 20:12:31 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		process_double_instruction(char *instruction, t_push_swap *ps)
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

int		process_instruction(char *raw_instruction, t_push_swap *ps,
			int verbosed)
{
	char *instruction;

//	print_push_swap_state(ps, 1);
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
	else if (process_double_instruction(instruction, ps))
		return (ft_free_turn(instruction, 1));
	if (verbosed)
		ft_printf("%s\n", instruction);
	return (ft_free_turn(instruction, 0));
}
