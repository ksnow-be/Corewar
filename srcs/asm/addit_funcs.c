/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 15:49:14 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/07/20 15:56:54 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int			ft_iswhitespace(char const c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int			base(int c, int base)
{
	char	*str;
	char	*str2;
	int		i;

	str = "0123456789abcdef";
	str2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str2[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int		nb;
	int		negatif;
	int		i;

	nb = 0;
	negatif = 1;
	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = -1;
		i++;
	}
	while (base(str[i], str_base) != -1)
	{
		nb = nb * str_base;
		nb = nb + base(str[i], str_base);
		i++;
	}
	return (nb * negatif);
}

int			index_detect(char *opname)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (!ft_strcmp(g_operations[i].name, opname))
			return (i);
		i++;
	}
	return (-1);
}

char		*extract_name(char *str)
{
	int		i;
	char	*tmp;
	char	*res;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] && str[i + 1] == 's')
		{
			if (i == 0)
				return (ft_strdup(".cor"));
			tmp = ft_strsub(str, 0, i);
			res = ft_strjoin(tmp, ".cor");
			if (tmp)
				free(tmp);
			return (res);
		}
		i++;
	}
	return (NULL);
}
