/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:33:42 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/20 12:35:21 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Keeps a process alive and tells that a player is alive.
*/

void    op_live(void *vm_ptr)
{
    t_vm    	*vm;
	t_champ		*champ;
	t_process	*proc;

    vm = (t_vm *)vm_ptr;
	champ = vm->champs.cur;
	proc = champ->procs.cur;
    proc->live = 1;

	if (vm->verbose & V_LIVES)
	    ft_printf("A process shows that player %u (%s) is alive\n", champ->id, champ->name);
	proc_set_pc(vm, proc, proc->pc + 5);
}
