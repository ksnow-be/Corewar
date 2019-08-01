/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexems.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:17:01 by vferry            #+#    #+#             */
/*   Updated: 2019/07/20 17:20:37 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*ft_undef_lex(t_cursor **cur, char **file, t_lexem *list)
{
	t_lexem	*new;

	new = ft_cr_init_list(list);
	new->line = (*cur)->line;
	new->start = (*cur)->pos;
	while (ft_is_undef(file[(*cur)->line][(*cur)->pos]) == 1)
		(*cur)->pos++;
	new->value = ft_strsub(file[(*cur)->line], new->start,
			(*cur)->pos - new->start);
	new->type = UNDEF;
	return (new);
}

t_lexem	*ft_hand_point(t_cursor **cur, char **file, t_lexem *list)
{
	int		i;
	int		j;
	t_lexem	*new;

	i = (*cur)->line;
	new = ft_cr_init_list(list);
	ft_mount_token(new, (*cur), file);
	j = (*cur)->pos;
	while (file[i] && file[i][j])
		while (file[i][j])
		{
			if (file[i][j] >= 'a' && file[i][j] <= 'z')
				j++;
			else
			{
				new->value = ft_strsub(file[i], new->start + 1,
						(j - new->start - 1));
				(*cur)->pos = j;
				return (new);
			}
			(*cur)->pos++;
		}
	ft_clean_lex(new);
	return (NULL);
}

void	ft_strcopy_clear(t_lexem *new, char *tmp)
{
	char	*buf;

	if (new->value == NULL)
		new->value = ft_strjoin("", tmp);
	else
	{
		buf = new->value;
		new->value = ft_strjoin(new->value, tmp);
		ft_strdel(&buf);
	}
	ft_strdel(&tmp);
}

int		cycle(char **file, t_lexem *new, int *i, int *j)
{
	int		fl;

	fl = 0;
	while (file[*i][*j] != '"')
		if (file[*i][*j] == '\0')
		{
			(*i)++;
			if (!file[*i])
			{
				ft_clean_lex(new);
				return (-1);
			}
			ft_strcopy_clear(new, ft_strsub(file[*i - 1], new->start + 1,
						(*j - new->start - 1)));
			*j = 0;
			new->start = -1;
			fl = 1;
		}
		else
			(*j)++;
	return (fl);
}

t_lexem	*ft_hand_string(t_cursor **cur, char **file, t_lexem *list)
{
	int		i;
	int		j;
	char	fl;
	t_lexem	*new;

	i = (*cur)->line;
	new = ft_cr_init_list(list);
	ft_mount_token(new, (*cur), file);
	j = (*cur)->pos;
	fl = cycle(file, new, &i, &j);
	(*cur)->line = i - 1;
	if (fl == -1)
		return (NULL);
	if (fl == 0)
	{
		new->value = ft_strsub(file[i], new->start + 1, (j - new->start - 1));
		(*cur)->pos = j + 1;
		(*cur)->line = i;
		return (new);
	}
	ft_strcopy_clear(new, ft_strsub(file[i], new->start + 1,
				(j - new->start - 1)));
	(*cur)->line = i;
	(*cur)->pos = j + 1;
	return (new);
}
