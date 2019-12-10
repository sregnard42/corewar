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

static void vm_fork(t_vm *vm, t_process *proc_cur, unsigned int pc)
{
    t_process   *proc;

    proc = proc_new(vm);
    ft_memcpy(proc->reg, proc_cur->reg, sizeof(t_reg));
    proc->live = proc_cur->live;
    proc->carry = proc_cur->carry;
	proc_set_pc(vm, proc, pc);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("forked a new process at PC %u\n", proc->pc);
	vm->print == &printw ? wait_input() : 0;
}

static unsigned int	get_target(t_vm *vm)
{
	t_arg			*arg;

	arg = arg_new(vm);
	arg->type = DIR_CODE; 
	get_param(vm, arg, FORK);
	return (arg->val);
}

/*
**		Takes an indirect. Creates a new process that inherits from his parent
**      except for the PC, that must be PC + (1st param % IDX_MOD).
*/

void	    op_fork(void *vm_ptr)
{
    t_vm			*vm;
	unsigned int	val;

    vm = (t_vm *)vm_ptr;
	val = get_target(vm);
	vm->print("fork %u | ", val);
    vm_fork(vm, vm->procs.cur, vm->pc + (val % IDX_MOD));
}

/*
**		Takes an indirect. Creates a new process that inherits from his parent
**      except for the PC, that must be PC + 1st param.
*/

void	    op_lfork(void *vm_ptr)
{
    t_vm			*vm;
	unsigned int	val;

    vm = (t_vm *)vm_ptr;
	val = get_target(vm);
	vm->print("lfork %u | ", val);
    vm_fork(vm, vm->procs.cur, vm->pc + val);
}
