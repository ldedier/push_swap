/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 18:22:12 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/09 20:11:36 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"

typedef struct		s_item
{
	int				value;
	int				index;
}					t_item;

typedef struct		s_push_swap
{
	t_list			*pile_a;
	t_list			*pile_b;
	int				nb_values;
}					t_push_swap;


int		log_error(char *str);
int		print_usage(char *progname);
void	print_pile(t_list *pile);
void	print_push_swap_state(t_push_swap *ps, int colored);
int		print_error(void);
int		parse_args_ps(int start, int argc, char **argv, t_push_swap *ps);
void	process_swap(t_list *pile);
void	process_push(t_list **receiver, t_list **giver);
int		process_instruction(char *instru, t_push_swap *ps, int verbosed);
void	process_rotate(t_list **pile);
void	process_reverse_rotate(t_list **pile);
int		is_solved_push_swap(t_push_swap *ps);
int		is_sorted_pile(t_list *pile);
void	free_push_swap(t_push_swap *ps);
#endif
