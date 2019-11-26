/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:13:57 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/25 23:12:22 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**      Creates a new process, with the following elements copied from his
**      parent: cycle, registers, live, carry.
*/

static void proc_dup(t_vm *vm, t_process *proc_cur)
{
    t_process   *proc;

    proc = proc_new(vm);
    // copier les registres
    proc->live = proc_cur->live;
    proc->carry = proc_cur->carry;
}

/*
**		Takes an indirect. Creates a new process that inherits from his parent
**      except for the PC, that must be PC + (1st param % IDX_MOD).
*/

void	    op_fork(void *vm_ptr)
{
    t_vm	*vm;
	t_args	*args;

    vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
    proc_dup(vm, vm->procs.cur);
    vm->procs.cur->pc = vm->pc + (args->first->val % IDX_MOD);
}

/*
**		Takes an indirect. Creates a new process that inherits from his parent
**      except for the PC, that must be PC + 1st param.
*/

void	    op_lfork(void *vm_ptr)
{
    t_vm    *vm;
	t_args	*args;

    vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
    proc_dup(vm, vm->procs.cur);
    vm->procs.cur->pc = vm->pc + args->first->val;
}
