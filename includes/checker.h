/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 19:29:34 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 05:46:08 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "push_swap.h"
# include <SDL2/SDL.h>
# include <SDL2_image/SDL_image.h>
# include <SDL2_ttf/SDL_ttf.h>
# include <SDL2_mixer/SDL_mixer.h>

typedef struct		s_visu
{
	char			active;
}					t_visu;

typedef struct		s_checker
{
	t_push_swap		ps;
	t_visu			visu;
	int				nb_instructions;
	char			verbosed;
	char			colored;
	char			show_nb_instructions;
}					t_checker;

int					parse_instructions(t_checker *checker);
void				free_all(t_checker *checker);
void				parse_flags(int argc, char **argv,
						int *index, t_checker *checker);
#endif
