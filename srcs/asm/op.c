/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksnow-be <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:58:00 by ksnow-be          #+#    #+#             */
/*   Updated: 2019/07/19 18:58:01 by ksnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

t_command	g_operations[17] =
{
	{"live", 0, 1, 4, {T_DIR}, 0x01, 0, 0, 0, 0},
	{"ld", 1, 2, 4, {T_DIR | T_IND, T_REG}, 0x02, 0, 0, 0, 0},
	{"st", 1, 2, 4, {T_REG, T_REG | T_IND}, 0x03, 0, 0, 0, 0},
	{"add", 1, 3, 4, {T_REG, T_REG, T_REG}, 0x04, 0, 0, 0, 0},
	{"sub", 1, 3, 4, {T_REG, T_REG, T_REG}, 0x05, 0, 0, 0, 0},
	{"and", 1, 3, 4, {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		0x06, 0, 0, 0, 0},
	{"or", 1, 3, 4,
		{T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		0x07, 0, 0, 0, 0},
	{"xor", 1, 3, 4,
		{T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
		0x08, 0, 0, 0, 0},
	{"zjmp", 0, 1, 2, {T_DIR}, 0x09, 0, 0, 0, 0},
	{"ldi", 1, 3, 2, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		0x0a, 0, 0, 0, 0},
	{"sti", 1, 3, 2, {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
		0x0b, 0, 0, 0, 0},
	{"fork", 0, 1, 2, {T_DIR}, 0x0c, 0, 0, 0, 0},
	{"lld", 1, 2, 4, {T_DIR | T_IND, T_REG}, 0x0d, 0, 0, 0, 0},
	{"lldi", 1, 3, 2, {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
		0x0e, 0, 0, 0, 0},
	{"lfork", 0, 1, 2, {T_DIR}, 0x0f, 0, 0, 0, 0},
	{"aff", 1, 1, 4, {T_REG}, 0x10, 0, 0, 0, 0},
	{0, 0, 0, 0, {0}, 0, 0, 0, 0, 0}
};
