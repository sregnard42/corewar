/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:53:46 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 18:42:44 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	check_champs(t_vm *vm)
{
	t_champs	*champs;
	t_champ		*champ;

	champs = &vm->champs;
	champ = champs->first;
	while (champ)
	{
		if (champs->size < 2)
			return ;
		if (champ->lives == 0)
		{
			if (vm->verbose & V_DEATHS)
				ft_printf("Player %d, \"%s\" died !\n", champ->id, champ->name);
			champs->cur = champ->prev;
			champs_del(champs, &champ);
			champ = champs->cur;
			continue ;
		}
		champ->lives = 0;
		champ = champ->next;
	}
}

static void	cycle_to_die(t_vm *vm)
{
		if (vm->cycle % vm->cycle_to_die == 0)
		{
			check_champs(vm);
			if 	(vm->nbr_live >= NBR_LIVE || vm->checks > MAX_CHECKS)
			{
				vm->cycle_to_die -= CYCLE_DELTA;
				if (vm->verbose & V_CYCLES)
					ft_printf("Cycle to die is now %d\n", vm->cycle_to_die);
			}
		}
		else
			++vm->checks;
}

static void	check_procs(t_vm *vm)
{
	t_process	*proc;

	proc = vm->procs.last;
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
				proc->champ->name);
			procs_del(vm, &vm->procs, &proc);
			proc = vm->procs.cur;
			continue ;
		}
		proc_exec(vm, proc->champ, proc);
		proc = proc->prev;
	}
}

static void	fight_intro(t_vm *vm)
{
	t_champ	*champ;

	ft_printf("Introducing contestants...\n");
	champ = vm->champs.first;
	while (champ)
	{
		ft_printf ("* Player %d, weighing %d bytes, \"%s\", (\"%s\") !\n",
		champ->id, champ->prog_size, champ->name, champ->comment);
		champ = champ->next;
	}
	vm->winner = vm->champs.last;
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
		check_procs(vm);
		cycle_to_die(vm);
		vm->flags & VM_VISU ? arena_print(vm, VISU_COLS) : 0;
	}
	if (vm->champs.size == 1)
		ft_printf("Contestant %d, \"%s\", has won !\n",
		vm->winner->id, vm->winner->name);
	else if (vm->flags & VM_DUMP)
		arena_print(vm, DUMP_COLS);
}
