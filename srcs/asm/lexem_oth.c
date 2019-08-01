/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_oth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:40:38 by vferry            #+#    #+#             */
/*   Updated: 2019/07/27 16:48:39 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		ft_lable_chars(t_cursor **cur, char **file)
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
			if (file[i][j] == ':')
				return (1);
			else
				break ;
		}
		j++;
	}
	if (file[i][j] == '\0')
		(*cur)->pos = j;
	return (0);
}

t_lexem	*ft_instruct_lex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem	*new;
	int		i;
	int		j;

	i = (*cur)->line;
	j = (*cur)->pos;
	new = ft_cr_init_list(list);
	new->type = INSTRUCT;
	new->line = (*cur)->line;
	new->start = (*cur)->start;
	new->value = ft_strsub(file[i], (*cur)->start, (j - (*cur)->start));
	return (new);
}

t_lexem	*ft_instal_lexm_sec(t_cursor **cur, char **file, t_lexem *list)
{
	if (ft_lable_chars(cur, file) == 1)
		return (ft_labch_lex(cur, file, list));
	else
		return (ft_instruct_lex(cur, file, list));
}

t_lexem	*ft_instal_lexm(t_cursor **cur, char **file, t_lexem *list)
{
	if (file[(*cur)->line][(*cur)->pos] == ',' || file[(*cur)->line]
		[(*cur)->pos] == '%' || file[(*cur)->line][(*cur)->pos] == ':')
		return (0);
	if (ft_isdigit(file[(*cur)->line][(*cur)->pos]) == 1)
		return (ft_hand_diglex(cur, file, list));
	if (file[(*cur)->line][(*cur)->pos] == 'r' &&
		(ft_isdigit(file[(*cur)->line][(*cur)->pos + 1]) == 1
		|| file[(*cur)->line][(*cur)->pos + 1] == '-'
		|| file[(*cur)->line][(*cur)->pos + 1] == '+'))
	{
		(*cur)->pos++;
		return (ft_reg_lex(cur, file, list));
	}
	else if (ft_is_symbol(file, (*cur)) == 1)
		return (ft_instal_lexm_sec(cur, file, list));
	return (NULL);
}
