/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_lex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:20:23 by vferry            #+#    #+#             */
/*   Updated: 2019/07/26 18:20:45 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_mount_token(t_lexem *new, t_cursor *cur, char **file)
{
	if (file[cur->line][cur->pos] == '.')
	{
		new->type = COMMAND;
		new->line = cur->line;
		new->start = cur->pos;
		cur->pos++;
	}
	else if (file[cur->line][cur->pos] == '"')
	{
		new->type = STRING;
		new->line = cur->line;
		new->start = cur->pos;
		cur->pos++;
	}
}

t_lexem	*ft_def_lex(t_cursor *cur, char **file, t_lexem *list)
{
	if (file[cur->line][cur->pos] == '.')
		return (ft_hand_point(&cur, file, list));
	else if (file[cur->line][cur->pos] == '"')
		return (ft_hand_string(&cur, file, list));
	else if ((ft_is_symbol(file, cur) == 1) && file[cur->line][cur->pos] != '_')
		return (ft_instal_lexm(&cur, file, list));
	else if (file[cur->line][cur->pos] == '%')
		return (ft_check_pct(&cur, file, list));
	else if (file[cur->line][cur->pos] == ',')
		return (ft_handling_sep(&cur, list));
	else if (file[cur->line][cur->pos] == '#'
			|| file[cur->line][cur->pos] == ';')
		return (ft_handling_oktotopr(&cur, list));
	else if (file[cur->line][cur->pos] == ':')
		return (ft_indir_lexem(&cur, file, list));
	else if (file[cur->line][cur->pos] == '+'
			|| file[cur->line][cur->pos] == '-')
		return (ft_p_m_lex(&cur, file, list));
	else if (file[cur->line][cur->pos] == '_')
		return (ft_low_line_lex(&cur, file, list));
	else
		return (ft_undef_lex(&cur, file, list));
}

t_lexem	*peremot(t_lexem *head)
{
	t_lexem *tmp;

	tmp = head;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_take_lex(char **file, t_cursor *cur, t_lexem **list)
{
	t_lexem		*new;
	t_lexem		*ind;

	ind = peremot(*list);
	while (file[cur->line] && file[cur->line][cur->pos] != '\0')
		if (file[cur->line][cur->pos] == '\t'
				|| file[cur->line][cur->pos] == ' ')
			cur->pos++;
		else
		{
			if ((new = ft_def_lex(cur, file, ind)) == NULL)
				break ;
			if ((*list) == NULL)
			{
				(*list) = new;
				ind = (*list);
				new = new->next;
			}
			else
			{
				ind->next = new;
				ind = ind->next;
				new = new->next;
			}
		}
}
