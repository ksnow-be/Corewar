/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_frs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:07:07 by vferry            #+#    #+#             */
/*   Updated: 2019/07/26 18:10:54 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*ft_hand_diglex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem *new;

	new = ft_cr_init_list(list);
	new->type = INDIR;
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	while (ft_isdigit(file[(*cur)->line][(*cur)->pos]) == 1)
		(*cur)->pos++;
	new->value = ft_strsub(file[(*cur)->line], new->start,
			(*cur)->pos - new->start);
	return (new);
}

t_lexem	*ft_reg_lex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem *new;
	int		i;
	int		j;

	i = (*cur)->line;
	j = 0;
	new = ft_cr_init_list(list);
	new->type = REG;
	new->line = (*cur)->line;
	if (file[(*cur)->line][(*cur)->pos] == '-')
	{
		(*cur)->pos++;
		new->start = (*cur)->pos - 2;
	}
	else
		new->start = (*cur)->pos - 1;
	if (ft_only_dig(file[(*cur)->line], cur) == 1)
	{
		j = (*cur)->pos;
		new->value = ft_strsub(file[i], new->start + 1, (j - (new->start + 1)));
		return (new);
	}
	ft_clean_lex(new);
	return (NULL);
}

t_lexem	*ft_regchar_lexm(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem *new;
	int		i;
	int		j;

	new = ft_cr_init_list(list);
	new->type = DIR;
	new->line = (*cur)->line;
	new->start = (*cur)->pos - 1;
	if (ft_is_only_symbol(file, cur) == 1)
	{
		i = (*cur)->line;
		j = (*cur)->pos;
		new->value = ft_strsub(file[i], j - 1, (j - (j - 1)));
		return (new);
	}
	ft_clean_lex(new);
	return (NULL);
}

t_lexem	*ft_labch_lex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem *new;
	int		i;
	int		j;

	i = (*cur)->line;
	j = (*cur)->pos;
	new = ft_cr_init_list(list);
	new->type = LABEL;
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	new->value = ft_strsub(file[i], (*cur)->start, (j - (*cur)->start));
	(*cur)->pos++;
	return (new);
}
