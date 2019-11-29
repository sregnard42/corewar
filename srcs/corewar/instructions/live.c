/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:33:42 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/29 15:02:44 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static t_champ	*get_target(t_vm *vm)
{
	t_arg			*arg;
	unsigned int	id;

	id = 0;
	arg = arg_new(vm);
	arg->type = DIR_CODE; 
	get_val(vm, arg, LIVE);
	id = arg->val;
	if (id < 1 || id > vm->champs.size)
		return (NULL);
	return (vm->champs.byId[id]);
}

/*
**		Keeps a process alive and tells that a player is alive.
*/

void   			 op_live(void *vm_ptr)
{
    t_vm    	*vm;
	t_champ		*champ;
	t_process	*proc;

    vm = (t_vm *)vm_ptr;
	if (!(champ = get_target(vm)))
		return ;
	proc = vm->procs.cur;
    proc->live = 1;
	vm->winner = champ;
	champ->last_alive = vm->cycle;
	++champ->lives;
	vm_print(vm, V_LIVES)("A process shows that player %u (%s) is alive\n",
	champ->id, champ->name);
}
