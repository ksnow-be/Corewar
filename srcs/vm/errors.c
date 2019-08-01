/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <lgigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:33:25 by lgigi             #+#    #+#             */
/*   Updated: 2019/07/25 12:37:41 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ft_exit(t_vm *vm, t_player *pl, int exit_st)
{
	if (pl)
		free_player(pl);
	if (vm)
		free_vm(vm);
	exit(exit_st);
}

void	print_error(int err, unsigned int code_size, t_player *pl, t_vm *vm)
{
	write(1, "Error! ", 7);
	if (err == 0)
		write(1, "Can't allocate memory.\n", 23);
	else if (err == 1)
		write(1, "Not such file.\n", 15);
	else if (err == 2)
		write(1, "Permission denied!\n", 19);
	else if (err == 3)
		write(1, "File has an invalid header.\n", 28);
	else if (err == 4)
		ft_printf("Player weight too large (%u > %u).\n",
							code_size, CHAMP_MAX_SIZE);
	else if (err == 5)
		write(1, "Invalid player code size!\n", 26);
	else if (err == 6)
		write(1, "Player already exist.\n", 22);
	else if (err == 7)
		write(1, "Wrong player index!\n", 20);
	else if (err == 8)
		write(1, "Champion doesn't have name.\n", 28);
	else if (err == 9)
		write(1, "Parsing error.\n", 15);
	else if (err == 10)
		write(1, "Champion name is too long.\n", 27);
	return (ft_exit(vm, pl, 1));
}

void	check_extra(t_vm **vm, t_player *player)
{
	if (!player->name[0])
		print_error(8, 0, player, *vm);
	else if (player->name[PROG_NAME_LENGTH + 3]\
		|| ft_strlen(player->name) > PROG_NAME_LENGTH)
		print_error(10, 0, player, *vm);
	else if (!player->code_size)
		ft_printf("Warning! Player %d \"%s\" has no code.\n",
								player->num, player->name);
}
