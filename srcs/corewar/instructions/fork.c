/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:13:57 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/29 14:00:34 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**      Creates a new process, with the following elements copied from his
**      parent: cycle, registers, live, carry.
*/

static void vm_fork(t_vm *vm, t_process *proc_cur, int pc)
{
    int i;
    t_process   *proc;

    proc = proc_new(vm);
    i = 0;
    while (++i <= REG_NUMBER)
        regcpy(&proc->reg[i], &proc_cur->reg[i], sizeof(REG_SIZE));
    proc->live = proc_cur->live;
    proc->carry = proc_cur->carry;
	proc_set_pc(vm, proc, pc);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("forked a new process at PC %d\n", proc->pc);
	vm->print == &printw ? wait_input() : 0;
}

static short int	get_target(t_vm *vm)
{
	t_arg			*arg;

	arg = arg_new(vm);
	arg->type = DIR_CODE; 
	get_param(vm, arg, FORK);
	return (arg->val);
}

/*
**		Takes an index. Creates a new process that inherits from his parent
**      except for the PC, that must be PC + (1st param % IDX_MOD).
*/

void	    op_fork(void *vm_ptr)
{
    t_vm			*vm;
	short int		val;

    vm = (t_vm *)vm_ptr;
	val = get_target(vm);
	vm->print("P %4d | ", vm->procs.cur->pid);
	vm->print("fork %%%d | ", val);
    vm_fork(vm, vm->procs.cur, vm->pc + (val % IDX_MOD));
}

/*
**		Takes an index. Creates a new process that inherits from his parent
**      except for the PC, that must be PC + 1st param.
*/

void	    op_lfork(void *vm_ptr)
{
    t_vm			*vm;
	short int		val;

    vm = (t_vm *)vm_ptr;
	val = get_target(vm);
	vm->print("P %4d | ", vm->procs.cur->pid);
	vm->print("lfork %%%d | ", val);
    vm_fork(vm, vm->procs.cur, vm->pc + val);
}
