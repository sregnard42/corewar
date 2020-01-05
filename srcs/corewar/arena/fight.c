/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:53:46 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/29 14:17:47 by sregnard         ###   ########.fr       */
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
			vm_print(vm, V_DEATHS)("Player %d, \"%s\" died !\n",
			champ->id, champ->name);
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
		if (vm->cycle == vm->cycle_check)
		{
		    vm->print("vm->checks: %d - MAX_CHECKS: %d\n", vm->checks, MAX_CHECKS);
			check_champs(vm);
			if 	(vm->nbr_live >= NBR_LIVE || ++vm->checks >= MAX_CHECKS)
			{
				vm->cycle_to_die -= CYCLE_DELTA;
				vm_print(vm, V_CYCLES)("Cycle to die is now %d\n",
				vm->cycle_to_die);
				vm->checks = 0;
			}
			vm->nbr_live = 0;
			vm->cycle_check = vm->cycle + vm->cycle_to_die;
		}
}

static void	check_procs(t_vm *vm)
{
	t_process	*proc;

	proc = vm->procs.last;
	while (proc)
	{
		if (vm->cycle == vm->cycle_check)
		{
			if (proc->live)
				proc->live = 0;
			else
			{
				vm_print(vm, V_DEATHS)
				("Process %d hasn't lived for %d cycles (CTD %d)\n",
				proc->pid, vm->cycle_to_die, vm->cycle_to_die);
				vm->procs.cur = proc->prev;
				procs_del(vm, &vm->procs, &proc);
				proc = vm->procs.cur;
				continue ;
			}
		}
		proc_exec(vm, proc->champ, proc);
		proc = proc->prev;
	}
}

static void	fight_intro(t_vm *vm)
{
	t_champ	*champ;

	vm->print("Introducing contestants...\n");
	champ = vm->champs.first;
	while (champ)
	{
		vm->print("* Player %d, weighing %d bytes, \"%s\", (\"%s\") !\n",
		champ->id, champ->prog_size, champ->name, champ->comment);
		champ = champ->next;
	}
	vm->winner = vm->champs.last;
	vm->flags & VM_VISU ? wait_input() : 0;
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
		vm->flags & VM_VISU ? erase() : 0;
		vm_print(vm, V_CYCLES)("It is now cycle %d\n", vm->cycle);
		if (vm->flags & VM_VISU && vm->cycle % 1 == 0)
			arena_print(vm, VISU_COLS);
		check_procs(vm);
		cycle_to_die(vm);
	}
	if (vm->flags & VM_DUMP && vm->cycle >= vm->dump)
	{
		vm->flags & VM_VISU ? erase() : 0;
		arena_print(vm, DUMP_COLS);
	}
	else
		vm->print("Contestant %d, \"%s\", has won !\n",
				  vm->winner->id, vm->winner->name);
	vm->flags & VM_VISU ? wait_input() : 0;
}
