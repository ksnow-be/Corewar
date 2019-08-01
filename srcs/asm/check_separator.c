/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:24:29 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/26 12:24:29 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*check_separator(t_lexem *lexem)
{
	lexem = check_next_lexem(lexem);
	if (lexem->type == SEP)
	{
		if (!(ft_strlen(lexem->value) == 1 &&
		lexem->value[0] == SEPARATOR_CHAR))
			ft_error("wrong separator", lexem);
	}
	else
		ft_error("wrong separator", lexem);
	return (lexem);
}

t_lexem	*check_extra_separators(t_lexem *lexem)
{
	if (lexem->value[0] == SEPARATOR_CHAR)
		ft_error("too many separators", lexem);
	else
		ft_error("wrong separator", lexem);
	lexem = check_next_lexem(lexem);
	return (lexem);
}

t_lexem	*check_comment(t_lexem *lexem)
{
	if (lexem->type == COMMENT)
		lexem = check_next_lexem(lexem);
	return (lexem);
}

void	check_eof(void)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (g_helper->file[i])
		i++;
	while (g_helper->file[i - 1][j])
	{
		if (g_helper->file[i - 1][j] == '\t')
			k = k + 3;
		k++;
		j++;
	}
	if (g_helper->file[i - 1][0])
	{
		ft_printf("line %d:%d:\033[0;31m error: \033[0m%s\n", i, k,
			"no empty line at the end of file");
		ft_printf("%s\n", g_helper->file[i - 1]);
		ft_printf("\033[0;31m%*c\033[0m\n", k + 1, 94);
		g_helper->count_errors++;
	}
}
