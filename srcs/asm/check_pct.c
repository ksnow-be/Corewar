/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:57:57 by vferry            #+#    #+#             */
/*   Updated: 2019/07/27 16:52:28 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*ft_direct_lex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem	*new;

	new = ft_cr_init_list(list);
	new->type = DIR;
	new->line = (*cur)->line;
	if (file[(*cur)->line][(*cur)->pos + 1] == '-')
	{
		(*cur)->pos += 2;
		new->start = (*cur)->pos - 2;
	}
	else
	{
		(*cur)->pos++;
		new->start = (*cur)->pos - 1;
	}
	if (ft_only_dig(file[(*cur)->line], cur) == 1)
	{
		new->value = ft_strsub(file[(*cur)->line], new->start + 1,
				((*cur)->pos - (new->start + 1)));
		return (new);
	}
	ft_clean_lex(new);
	return (NULL);
}

int		ft_lable_check_chars(t_cursor **cur, char **file)
{
	int		i;
	int		j;

	i = (*cur)->line;
	j = (*cur)->pos;
	(*cur)->start = -1;
	while (file[i][j])
	{
		if ((*cur)->start == -1)
			(*cur)->start = j;
		if (!(file[i][j] == '_' || (file[i][j] >= '0' && file[i][j] <= '9') ||
			(file[i][j] >= 'a' && file[i][j] <= 'z')))
		{
			(*cur)->pos = j;
			return (1);
		}
		j++;
	}
	if (file[i][j] == '\0')
	{
		(*cur)->pos = j;
		return (1);
	}
	return (0);
}

t_lexem	*ft_direct_lab_lex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_cr_init_list(list);
	new->type = DIR_LABEL;
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	(*cur)->pos += 2;
	if (ft_lable_check_chars(cur, file) == 1)
	{
		i = (*cur)->line;
		j = (*cur)->pos;
		new->value = ft_strsub(file[i], (*cur)->start, (j - (*cur)->start));
		return (new);
	}
	ft_clean_lex(new);
	return (NULL);
}

t_lexem	*ft_check_pct(t_cursor **cur, char **file, t_lexem *list)
{
	int		i;
	int		j;

	i = (*cur)->line;
	j = (*cur)->pos;
	if (ft_isdigit(file[i][j + 1]) || file[i][j + 1] == '-'
			|| file[i][j + 1] == '+')
		return (ft_direct_lex(cur, file, list));
	else if (file[i][j + 1] == ':')
		return (ft_direct_lab_lex(cur, file, list));
	else
	{
		(*cur)->pos++;
		return (ft_undef_lex(cur, file, list));
	}
}
