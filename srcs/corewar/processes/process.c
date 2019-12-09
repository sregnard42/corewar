/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:21:55 by cmouele           #+#    #+#             */
/*   Updated: 2019/12/09 20:43:41 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new process, which adds itself to a champion's processes
**			list
*/

t_process	*proc_new(t_vm *vm)
{
	static int	pid = 1;
	t_process	*proc;

	if (!vm || !vm->champs.cur)
		ft_error(vm, &vm_free, "proc_new args\n");
	if (!(proc = ft_memalloc(sizeof(t_process))))
		ft_error(vm, &vm_free, "proc_new memalloc\n");
	ft_bzero(&proc->args, sizeof(t_args));
	proc->pid = pid++;
	proc->champ = vm->champs.cur;
	proc->list = &vm->procs;
	procs_add(vm, proc->list, proc);
	ft_bzero(&proc->reg, sizeof(t_reg) * (REG_NUMBER + 1));
	regcpy(&proc->reg[1], &proc->champ->id, REG_SIZE);
	proc->pc = proc->champ->pos;
	vm->colors[proc->pc] = proc->champ->id + 10;
	return (proc);
}

void		proc_exec(t_vm *vm, t_champ *champ, t_process *proc)
{
	int		opcode;

	vm->champs.cur = champ;
	vm->procs.cur = proc;
	opcode = arena_get(vm, proc->pc);
	if (opcode < 1 || opcode > 16)
		return ;
	if (proc->cycle == 0)
		proc->cycle = vm->cycle + op_cycles[opcode];
	if (proc->cycle > vm->cycle)
		return ;
	proc->cycle = 0;
	vm->pc = proc->pc;
	proc_set_pc(vm, proc, proc->pc + 1);
	ocp(vm, opcode);
	vm->print = vm_print(vm, V_OPERATIONS);
	op[opcode](vm);
	vm->print = vm_print(vm, 0);
	args_free(&proc->args);
}

void		proc_set_pc(t_vm *vm, t_process *proc, unsigned int pc)
{
	vm->colors[proc->pc] = proc->champ->id;
	if (pc >= MEM_SIZE)
		pc &= MEM_SIZE;
	else if (pc < 0)
		pc = pc & -MEM_SIZE + MEM_SIZE - 1;
	if (pc < 0 || pc >= MEM_SIZE)
		ft_error(vm, &vm_free, "PC out of arena !\n");
	proc->pc = pc;
	vm->colors[pc] = proc->champ->id + 10;
}
