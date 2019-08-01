/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:04:02 by vferry            #+#    #+#             */
/*   Updated: 2019/07/26 14:45:10 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		ft_is_symbol(char **file, t_cursor *cur)
{
	if ((file[cur->line][cur->pos] >= '0' && file[cur->line][cur->pos] <= '9')
		|| (file[cur->line][cur->pos] >= 'a'
		&& file[cur->line][cur->pos] <= 'z')
		|| file[cur->line][cur->pos] == '_')
		return (1);
	return (0);
}

int		ft_is_only_symbol(char **file, t_cursor **cur)
{
	int		i;
	int		j;

	i = (*cur)->line;
	j = (*cur)->pos;
	while (file[i][j])
	{
		if (!(file[i][j] >= 'a' && file[i][j] <= 'z'))
		{
			(*cur)->pos = j;
			return (1);
		}
		j++;
	}
	return (0);
}

int		ft_only_dig(char *line, t_cursor **cur)
{
	int		j;

	j = (*cur)->pos;
	while (line[j])
	{
		if (!ft_isdigit(line[j]))
		{
			(*cur)->pos = j;
			return (1);
		}
		j++;
	}
	if (line[j] == '\0')
	{
		(*cur)->pos = j;
		return (1);
	}
	return (0);
}

int		check_format(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (len < 2 || name[len - 1] != 's' || name[len - 2] != '.')
		return (1);
	return (0);
}

int		ft_is_undef(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
		return (0);
	if (c == '_')
		return (1);
	if (c == '#' || c == ',' || c == ':')
		return (0);
	if (c == '.' || c == '"' || c == '%')
		return (0);
	else
		return (1);
}
