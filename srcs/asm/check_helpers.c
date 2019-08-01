/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:26:12 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/26 12:26:13 by sbruen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void	ft_error(char *error, t_lexem *lexem)
{
	ft_printf("line %d:%d:\033[0;31m error: \033[0m%s\n", lexem->line + 1,
			lexem->start + 1, error);
	ft_printf("%s\n", g_helper->file[lexem->line]);
	ft_printf("\033[0;31m%*c\033[0m\n", lexem->start + 1, 94);
	g_helper->count_errors++;
}

t_lexem	*error_next_lexem(t_lexem *lexem, char *error)
{
	ft_error(error, lexem);
	lexem = check_next_lexem(lexem);
	return (lexem);
}

void	errors_check(void)
{
	if (g_helper->count_errors)
	{
		printf("errors: %d\n", g_helper->count_errors);
		exit(19);
	}
}

void	free_twod_array(char **array)
{
	int		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	memory_cleaner(void)
{
	free_twod_array(g_helper->file);
	if (g_helper->labels)
		free_twod_array(g_helper->labels);
	free(g_helper);
}
