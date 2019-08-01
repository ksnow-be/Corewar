/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aleh_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:32:08 by vferry            #+#    #+#             */
/*   Updated: 2019/07/20 14:18:48 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_clean_file(char **file)
{
	int i;

	i = 0;
	while (file[i])
	{
		ft_strdel(&file[i]);
		i++;
	}
	ft_strdel(&file[i]);
	free(file);
}

void	ft_clean_lex(t_lexem *del)
{
	if (del->value)
		ft_strdel(&del->value);
	free(del);
}
