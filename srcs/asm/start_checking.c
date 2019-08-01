/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferry <vferry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:24:40 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/26 18:19:23 by vferry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem		*check_next_lexem(t_lexem *lexem)
{
	g_helper->count_lexem--;
	if (lexem->next)
		lexem = lexem->next;
	else
		return (lexem);
	lexem = check_comment(lexem);
	return (lexem);
}

void		fill_labels(t_lexem *lexem, t_helper *helper)
{
	while (lexem)
	{
		if (lexem->type == LABEL)
		{
			helper->labels = (char **)realloc(helper->labels, sizeof(char *) *
			(helper->count_labels + 1));
			helper->labels[helper->count_labels - 1] = ft_strdup(lexem->value);
			helper->labels[helper->count_labels] = NULL;
			helper->count_labels++;
		}
		lexem = lexem->next;
	}
}

void		copy_file(char **file, int lines)
{
	int		i;

	i = 0;
	g_helper->file = (char **)malloc(sizeof(char *) * (lines + 1));
	while (file[i])
	{
		g_helper->file[i] = ft_strdup(file[i]);
		i++;
	}
	g_helper->file[i] = NULL;
}

void		init_structs(t_lexem *lexem, char **file, int lines)
{
	g_helper = (t_helper *)malloc(sizeof(t_helper));
	g_helper->file = NULL;
	g_helper->labels = NULL;
	g_helper->count_labels = 1;
	g_helper->count_errors = 0;
	g_helper->count_lexem = 0;
	copy_file(file, lines);
	fill_labels(lexem, g_helper);
	count_lexems(lexem);
}

void		start_checking(t_lexem *lexem, char **file, int lines)
{
	init_structs(lexem, file, lines);
	lexem = check_champion(lexem);
	while (g_helper->count_lexem-- > 0)
	{
		if (lexem->type == COMMAND)
			lexem = error_next_lexem(lexem, "wrong command");
		else if (lexem->type == STRING)
			lexem = error_next_lexem(lexem, "wrong string");
		else if (lexem->type == INSTRUCT)
			lexem = check_instructions(lexem);
		else if (lexem->type == LABEL)
			lexem = check_next_lexem(lexem);
		else if (lexem->type == SEP)
			lexem = check_separator(lexem);
		else if (lexem->type == UNDEF)
			lexem = error_next_lexem(lexem, "undefined input");
		else if (lexem->type == DIR || lexem->type == INDIR ||
		lexem->type == DIR_LABEL || lexem->type == INDIR_LABEL)
			lexem = error_next_lexem(lexem, "incorrect argument");
		else
			exit(100);
	}
	check_eof();
	errors_check();
	memory_cleaner();
}
