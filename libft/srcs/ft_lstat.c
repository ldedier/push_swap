/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 20:55:23 by ldedier           #+#    #+#             */
/*   Updated: 2019/02/01 20:57:11 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstat(t_list *list, int index)
{
	t_list	*ptr;
	int		i;

	i = 0;
	ptr = list;
	while (ptr != NULL)
	{
		if (i++ == index)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
