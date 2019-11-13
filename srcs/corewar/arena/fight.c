/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:53:46 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/13 17:50:33 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	round_procs(t_vm *vm, t_champ *champ)
{
	t_process	*proc;

	proc = champ->procs.first;
	while (proc)
	{
		if (!proc->live)
		{
			ft_printf("Process is now dead !\n");
			procs_del(vm, &champ->procs, &proc);
			proc = champ->procs.cur;
			continue ;
		}
		proc = proc->next;
	}

}

static void	round_champs(t_vm *vm)
{
	t_champs	*champs;
	t_champ		*champ;

	champs = &vm->champs;
	champ = champs->first;
	while (champ)
	{
		if (champ->procs.size == 0)
		{
			ft_printf("I'm dead ! [%s]\n", champ->name);
			champs_del(champs, &champ);
			champ = champs->cur;
			continue ;
		}
		else
		{
			ft_printf("I'm alive with %d process(es) ! [%s]\n", champ->procs.size, champ->name);
			round_procs(vm, champ);
		}
		champ = champ->next;
	}
}

void		fight(t_vm *vm)
{
	while (vm->champs.size &&\
		!(vm->flags & VM_DUMP && vm->cycle >= vm->dump))
	{
		round_champs(vm);
		++vm->cycle;
	}
	//vm->flags & VM_DUMP ? arena_print(vm) : 0;
}
