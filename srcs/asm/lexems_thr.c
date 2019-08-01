/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_thr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:01:38 by vferry            #+#    #+#             */
/*   Updated: 2019/07/27 16:49:45 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*ft_minus_lex(t_cursor **cur, char **file, t_lexem *list)
{
	int		i;
	int		j;
	int		start;
	t_lexem	*new;

	i = (*cur)->line;
	j = (*cur)->pos;
	start = j;
	j++;
	if (ft_isdigit(file[i][j]) == 1)
	{
		while (ft_isdigit(file[i][j]) == 1)
			j++;
	}
	(*cur)->pos = j;
	new = ft_cr_init_list(list);
	new->type = INDIR;
	new->line = (*cur)->line;
	new->start = start;
	new->value = ft_strsub(file[i], start, ((*cur)->pos - start));
	return (new);
}

t_lexem	*ft_p_m_lex(t_cursor **cur, char **file, t_lexem *list)
{
	if (file[(*cur)->line][(*cur)->pos] == '+')
		return (ft_plus_lex(cur, file, list));
	else
		return (ft_minus_lex(cur, file, list));
}

t_lexem	*ft_low_line_lex(t_cursor **cur, char **file, t_lexem *list)
{
	int		i;
	int		j;

	i = (*cur)->line;
	j = (*cur)->pos;
	while (file[i][j] != ' ')
	{
		if (file[i][j] == ':')
			if (ft_lable_chars(cur, file) == 1)
				return (ft_labch_lex(cur, file, list));
		j++;
	}
	i = (*cur)->line;
	j = (*cur)->pos;
	if (file[i][j] == '_')
		return (ft_undef_lex(cur, file, list));
	return (NULL);
}
