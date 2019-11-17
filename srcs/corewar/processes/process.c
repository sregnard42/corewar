/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:21:55 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 16:58:34 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new process, which adds itself to a champion's processes
**			list
*/

t_process	*proc_new(t_vm *vm)
{
	t_process	*proc;

	if (!vm || !vm->champs.cur)
		ft_error(vm, &free_all, "proc_new args\n");
	if (!(proc = ft_memalloc(sizeof(t_process))))
		ft_error(vm, &free_all, "proc_new memalloc\n");
	ft_bzero(&proc->params, sizeof(t_params));
	proc->champ = vm->champs.cur;
	proc->list = &proc->champ->procs;
	procs_add(vm, &vm->champs.cur->procs, proc);
	ft_memcpy(&proc->reg[1], &vm->champs.cur->id, sizeof(int));
	proc_set_pc(vm, proc, vm->champs.cur->pos);
	return (proc);
}

void		proc_exec(t_vm *vm, t_champ *champ, t_process *proc)
{
	vm->champs.cur = champ;
	vm->champs.cur->procs.cur = proc;
	op[vm->arena[proc->pc]](vm);
}

void		proc_set_pc(t_vm *vm, t_process *proc, unsigned int pc)
{
	proc->pc = pc;
	vm->colors[pc] = proc->champ->id + 10;
}
