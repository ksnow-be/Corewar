/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:44:46 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/26 18:14:37 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	check_reg_argument(t_lexem *lexem)
{
	if (!(is_number(lexem->value) && ft_atoi(lexem->value) >= 0 &&
		ft_atoi(lexem->value) <= REG_NUMBER))
		ft_error("incorrect T_REG argument", lexem);
}

void	check_dir_indir_argument(t_lexem *lexem)
{
	if (!(is_number(lexem->value)))
	{
		if (lexem->type == DIR)
			ft_error("incorrect T_DIR argument", lexem);
		else
			ft_error("incorrect T_IND argument", lexem);
	}
}

void	check_label_argument(t_lexem *lexem)
{
	if (!(check_label(lexem->value)))
	{
		if (lexem->type == DIR_LABEL)
			ft_error("incorrect T_DIR argument", lexem);
		else
			ft_error("incorrect T_IND argument", lexem);
	}
}

int		check_argument_type(t_lexem *lexem, int i, int j)
{
	if (g_operations[i].args[j] == 7)
		return (1);
	else if (lexem->type == REG)
	{
		if (g_operations[i].args[j] == 1 || g_operations[i].args[j] == 3 ||
			g_operations[i].args[j] == 5)
			return (1);
	}
	else if (lexem->type == DIR || lexem->type == DIR_LABEL)
	{
		if (g_operations[i].args[j] == 2 || g_operations[i].args[j] == 3 ||
			g_operations[i].args[j] == 6)
			return (1);
	}
	else if (lexem->type == INDIR || lexem->type == INDIR_LABEL)
	{
		if (g_operations[i].args[j] == 4 || g_operations[i].args[j] == 5 ||
			g_operations[i].args[j] == 6)
			return (1);
	}
	return (0);
}
