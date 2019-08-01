/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <lgigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 16:36:58 by lgigi             #+#    #+#             */
/*   Updated: 2019/07/25 14:55:50 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	introduce_players(t_player *pl[MAX_PLAYERS])
{
	int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		if (pl[i])
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
												pl[i]->num, pl[i]->code_size,
												pl[i]->name, pl[i]->comment);
		i++;
	}
}

void	print_hex(t_vm *vm)
{
	int				i;
	int				cnt;

	i = -1;
	cnt = 0;
	while (++i < MEM_SIZE)
	{
		if (cnt == 0)
			ft_printf("0x%.4x : ", i);
		ft_printf("%02hhx ", vm->field[i]);
		cnt++;
		if ((vm->fl & FL_DUMP32) && cnt == 32)
			ft_putchar('\n');
		else if (((vm->fl & FL_DUMP) || (vm->fl & FL_S)) && cnt == 64)
			ft_putchar('\n');
		cnt = (cnt == 32 && (vm->fl & FL_DUMP32)) ? 0 : cnt;
		cnt = (cnt == 64 && ((vm->fl & FL_DUMP) || (vm->fl & FL_S))) ? 0 : cnt;
	}
	if (!(vm->fl & FL_S))
		ft_exit(vm, NULL, 1);
	else
	{
		vm->s_cycles = vm->d_cycles;
		read(0, &cnt, 1);
	}
}

void	print_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n", vm->last_live->num,
													vm->last_live->name);
}

void	print_usage(void)
{
	ft_printf("Usage:\n./corewar [-dump N -v N -n N -s N] [players]\n");
	ft_printf("-dump    : Dump memory after N cycles\n");
	ft_printf("-s N     : Runs N cycles, dumps memory, pauses, then repeats\n");
	ft_printf("-n N     : Choose order of champion\n");
	ft_printf("-v       : Verbosity levels of debug\n");
	ft_printf("           1 : Show lives\n");
	ft_printf("           2 : Show cycles\n");
	ft_printf("           4 : Show operatins\n");
	ft_printf("           8 : Show dies\n");
	exit(0);
}
