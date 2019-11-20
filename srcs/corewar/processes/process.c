/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:21:55 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/20 12:28:17 by sregnard         ###   ########.fr       */
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
	ft_bzero(&proc->args, sizeof(t_args));
	proc->champ = vm->champs.cur;
	proc->list = &proc->champ->procs;
	procs_add(vm, &vm->champs.cur->procs, proc);
	ft_memcpy(&proc->reg[1], &vm->champs.cur->id, sizeof(int));
	proc_set_pc(vm, proc, vm->champs.cur->pos);
	return (proc);
}

void		proc_exec(t_vm *vm, t_champ *champ, t_process *proc)
{
	int		opcode;

	vm->champs.cur = champ;
	vm->champs.cur->procs.cur = proc;
	opcode = arena_get(vm, proc->pc);
	if (opcode < 1 || opcode > 16)
		return ;
	op[opcode](vm);
}

void		proc_set_pc(t_vm *vm, t_process *proc, unsigned int pc)
{
	vm->colors[proc->pc] = proc->champ->id;
	if (pc >= MEM_SIZE)
		pc &= MEM_SIZE;
	else if (pc < 0)
		pc = pc & -MEM_SIZE + MEM_SIZE - 1;
	if (pc < 0 || pc >= MEM_SIZE)
		ft_error(vm, &free_all, "PC out of arena !\n");
	proc->pc = pc;
	vm->colors[pc] = proc->champ->id + 10;
}
