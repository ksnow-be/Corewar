/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:24:19 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/26 12:24:21 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		check_label(char *label)
{
	int		i;

	i = 0;
	while (g_helper->labels[i])
	{
		if (ft_strequ(g_helper->labels[i], label))
			return (1);
		i++;
	}
	return (0);
}
