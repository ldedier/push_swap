/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_atoiable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 22:17:36 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 03:56:16 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_atoiable(char *s, int *value)
{
	long	res;
	int		start;
	int		i;

	res = 0;
	start = 0;
	while (ft_isseparator(s[start]))
		start++;
	i = start;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
	{
		if ((s[start] != '-' && (res * 10 + s[i] - '0' <= 2147483647))
				|| (s[start] == '-' && (res * 10 + s[i] - '0' <= 2147483648)))
			res = res * 10 + s[i] - '0';
		else
			return (0);
		i++;
	}
	*value = (s[start] == '-' ? -res : res);
	return (1);
}
