/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems_sec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:59:46 by vferry            #+#    #+#             */
/*   Updated: 2019/07/26 18:07:31 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*ft_handling_sep(t_cursor **cur, t_lexem *list)
{
	t_lexem	*new;

	new = ft_cr_init_list(list);
	new->type = SEP;
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	new->value = ft_strnew(2);
	new->value[0] = ',';
	(*cur)->pos++;
	return (new);
}

t_lexem	*ft_handling_oktotopr(t_cursor **cur, t_lexem *list)
{
	t_lexem	*new;

	new = ft_cr_init_list(list);
	new->type = COMMENT;
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	new->value = ft_strnew(2);
	new->value[0] = '#';
	(*cur)->line++;
	(*cur)->pos = 0;
	return (new);
}

t_lexem	*ft_indir_lexem(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem	*new;
	int		i;
	int		j;

	new = ft_cr_init_list(list);
	new->type = INDIR_LABEL;
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	(*cur)->pos++;
	i = (*cur)->line;
	j = (*cur)->pos;
	while ((file[i][j] >= '0' && file[i][j] <= '9') ||
		(file[i][j] >= 'a' && file[i][j] <= 'z') || file[i][j] == '_')
		j++;
	(*cur)->pos = j;
	new->value = ft_strsub(file[i], new->start + 1,
			(*cur)->pos - new->start - 1);
	return (new);
}

t_lexem	*ft_plus_lex(t_cursor **cur, char **file, t_lexem *list)
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
		while (ft_isdigit(file[i][j]) == 1)
			j++;
	(*cur)->pos = j;
	new = ft_cr_init_list(list);
	new->type = INDIR;
	new->line = (*cur)->line;
	new->start = start;
	new->value = ft_strsub(file[i], start, ((*cur)->pos - start));
	return (new);
}
