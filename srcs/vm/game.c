/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <lgigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:09:22 by lgigi             #+#    #+#             */
/*   Updated: 2019/07/25 14:12:28 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		run_op(t_vm *vm, t_carriage *carr)
{
	ft_bzero((void *)carr->arg_types, sizeof(int) * 3);
	ft_bzero((void *)carr->arg_vals, sizeof(int) * 3);
	if (parse_args_codes(vm, carr, -1, 0))
		g_ops[carr->op - 1].f(vm, carr);
	if (carr->op != 9)
		carr->pos = (carr->pos + carr->to_next) % MEM_SIZE;
}

static void		carr_routine(t_vm *vm, t_carriage *carr)
{
	if (carr->cycles <= 0)
	{
		carr->op = vm->field[carr->pos % MEM_SIZE];
		if (carr->op > 16 || !carr->op)
			carr->cycles = 0;
		else
			carr->cycles = g_ops[carr->op - 1].cycles;
	}
	carr->cycles--;
	if (carr->cycles <= 0)
		run_op(vm, carr);
}

static int		game_check(t_carriage *carr)
{
	while (carr)
	{
		if (!carr->is_dead)
			return (1);
		carr = carr->next;
	}
	return (0);
}

static void		check_carriages(t_vm *vm, t_carriage *carr, int *i)
{
	vm->num_checks++;
	while (carr)
	{
		if (!carr->is_dead && ((vm->all_cycles - carr->alive)\
		>= vm->cycles_to_die || (vm->cycles_to_die < 0)))
		{
			if (vm->fl & FL_DEBUG4)
				ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					carr->n, vm->all_cycles - carr->alive, vm->cycles_to_die);
			carr->is_dead = 1;
		}
		carr = carr->next;
	}
	if (vm->live_operations >= NBR_LIVE || vm->num_checks >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->num_checks = 0;
		if (vm->fl & FL_DEBUG2)
			ft_printf("Cycle to die is now %d\n", vm->cycles_to_die);
	}
	vm->live_operations = 0;
	*i = 0;
}

void			game_routine(t_vm *vm, int i, t_carriage *cr)
{
	while (1)
	{
		vm->all_cycles++;
		if (!game_check(vm->carr))
			break ;
		if (vm->fl & FL_DEBUG2)
			ft_printf("It is now cycle %d\n", vm->all_cycles);
		i++;
		cr = vm->carr;
		while (cr)
		{
			if (!cr->is_dead)
				carr_routine(vm, cr);
			cr = cr->next;
		}
		if (vm->cycles_to_die == i || vm->cycles_to_die <= 0)
			check_carriages(vm, vm->carr, &i);
		vm->d_cycles -= ((vm->fl & FL_DUMP) || (vm->fl & FL_DUMP32)) ? 1 : 0;
		vm->s_cycles -= ((vm->fl & FL_S)) ? 1 : 0;
		if ((((vm->fl & FL_DUMP) || (vm->fl & FL_DUMP32)) && vm->d_cycles <= 0)\
		|| ((vm->fl & FL_S) && vm->s_cycles <= 0))
			print_hex(vm);
	}
	print_winner(vm);
}
