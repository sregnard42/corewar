/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:53:46 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/20 12:34:21 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	round_procs(t_vm *vm, t_champ *champ)
{
	t_process	*proc;

	proc = champ->procs.first;
	while (proc)
	{
		if (vm->cycle % vm->cycle_to_die == 0)
		{
			if (proc->live)
			{
				proc->live = 0;
				break ;
			}
			if (vm->verbose & V_DEATHS)
				ft_printf("A process is now dead ! it belonged to \"%s\" !\n",
				champ->name);
			procs_del(vm, &champ->procs, &proc);
			proc = champ->procs.cur;
			continue ;
		}
		proc_exec(vm, champ, proc);
		proc = proc->next;
	}
}

static void	round_champs(t_vm *vm)
{
	t_champs	*champs;
	t_champ		*champ;

	champs = &vm->champs;
	champ = champs->last;
	while (champ)
	{
		if (champs->size < 2)
			return ;
		round_procs(vm, champ);
		if (champ->procs.size == 0)
		{
			if (vm->verbose & V_DEATHS)
				ft_printf("Player %d, \"%s\" died !\n", champ->id, champ->name);
			champs->cur = champ->prev;
			champs_del(champs, &champ);
			champ = champs->cur;
			continue ;
		}
		champ = champ->prev;
	}
}

static void	fight_intro(t_vm *vm)
{
	t_champ	*champ;

	ft_printf("Introducing contestants...\n");
	champ = vm->champs.first;
	while (champ)
	{
		ft_printf ("* Player %d, weighing %d, \"%s\", (\"%s\")\n", champ->id,
		champ->prog_size, champ->name, champ->comment);
		champ = champ->next;
	}
}

void		fight(t_vm *vm)
{
	fight_intro(vm);
	vm->cycle = 0;
	while (vm->champs.size > 1 &&
		vm->cycle_to_die > 0 &&
		!(vm->flags & VM_DUMP && vm->cycle >= vm->dump))
	{
		++vm->cycle;
		if (vm->verbose & V_CYCLES)
			ft_printf("It is now cycle %d\n", vm->cycle);
		round_champs(vm);
		if (vm->cycle % vm->cycle_to_die == 0 &&
			(vm->nbr_live >= NBR_LIVE || vm->checks > MAX_CHECKS))
		{
			vm->cycle_to_die -= CYCLE_DELTA;
			if (vm->verbose & V_CYCLES)
				ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
		}
		else
			++vm->checks;
		vm->flags & VM_VISU ? arena_print(vm, VISU_COLS) : 0;
	}
	if (vm->champs.size == 1)
		ft_printf("Contestant %d, \"%s\", has won !\n",
		vm->champs.first->id, vm->champs.first->name);
	else if (vm->flags & VM_DUMP)
		arena_print(vm, DUMP_COLS);
}
