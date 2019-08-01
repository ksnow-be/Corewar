/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbruen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:23:59 by sbruen            #+#    #+#             */
/*   Updated: 2019/07/27 18:21:26 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_lexem	*check_string(t_lexem *lexem)
{
	if (!lexem->next)
	{
		ft_error("incorrect file", lexem);
		exit(1);
	}
	lexem = check_next_lexem(lexem);
	if (lexem->type != STRING)
		ft_error("wrong comment format", lexem);
	if (ft_strlen(lexem->value) > (COMMENT_LENGTH + 2))
		ft_error("maximum length of comment is 2048", lexem);
	lexem = check_next_lexem(lexem);
	return (lexem);
}

t_lexem	*check_name(t_lexem *lexem)
{
	if (!lexem->next)
	{
		ft_error("incorrect file", lexem);
		exit(1);
	}
	lexem = check_next_lexem(lexem);
	if (lexem->type != STRING)
		ft_error("wrong name format", lexem);
	if (ft_strlen(lexem->value) > (PROG_NAME_LENGTH + 2))
		ft_error("maximum length of name is 128", lexem);
	lexem = check_next_lexem(lexem);
	if (lexem->type == COMMAND && ft_strequ(lexem->value, "comment"))
		lexem = check_string(lexem);
	else
	{
		ft_error("incorrect comment command", lexem);
		lexem = check_string(lexem);
	}
	return (lexem);
}

t_lexem	*check_champion(t_lexem *lexem)
{
	lexem = check_comment(lexem);
	if (!lexem->next || lexem->type != COMMAND)
		ft_error("wrong champion description", lexem);
	if (ft_strequ(lexem->value, "name"))
		lexem = check_name(lexem);
	else
	{
		ft_error("incorrect name command", lexem);
		lexem = check_name(lexem);
	}
	return (lexem);
}
