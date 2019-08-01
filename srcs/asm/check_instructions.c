/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:24:10 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/26 18:15:38 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		is_number(char *num)
{
	int		i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

t_lexem	*check_instructions_arguments(t_lexem *lexem, int inst_index)
{
	int		i;

	i = 0;
	while (g_operations[inst_index].count_args > i)
	{
		lexem = check_next_lexem(lexem);
		if (!check_argument_type(lexem, inst_index, i))
			ft_error("incorrect argument type", lexem);
		if (lexem->type == REG)
			check_reg_argument(lexem);
		else if (lexem->type == DIR || lexem->type == INDIR)
			check_dir_indir_argument(lexem);
		else if (lexem->type == DIR_LABEL || lexem->type == INDIR_LABEL)
			check_label_argument(lexem);
		else if (lexem->type == SEP)
			lexem = check_extra_separators(lexem);
		if (g_operations[inst_index].count_args > (i + 1))
			lexem = check_separator(lexem);
		i++;
	}
	lexem = check_next_lexem(lexem);
	return (lexem);
}

int		check_instruction_names(t_lexem *lexem)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(lexem->value, g_operations[i].name))
			return (i);
		i++;
	}
	return (-1);
}

t_lexem	*check_instructions(t_lexem *lexem)
{
	int		inst_index;

	if ((inst_index = check_instruction_names(lexem)) < 0)
	{
		ft_error("instruction doesn't exist", lexem);
		lexem = check_next_lexem(lexem);
		while (lexem)
		{
			if (lexem->type == REG || lexem->type == INDIR_LABEL ||
			lexem->type == DIR || lexem->type == INDIR || lexem->type == SEP)
				lexem = lexem->next;
			else
				return (lexem);
		}
	}
	else
		lexem = check_instructions_arguments(lexem, inst_index);
	return (lexem);
}
