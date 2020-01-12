/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:15:35 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 12:15:36 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int  get_target(t_vm *vm)
{
    t_arg   *arg;

    arg = arg_new(vm);
    arg->type = DIR_CODE;
    get_param(vm, arg, ZJMP);
    return (arg->val);
}

/*
**		Takes an indirect. Jumps to the address of the index if carry == 1.
*/

void	    op_zjmp(void *vm_ptr)
{
    t_vm			*vm;
    t_process       *proc;
    short int       target;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    target = get_target(vm);
    vm->print("P %4d | ", proc->pid);
    vm->print("zjmp %d ", target);
    if (!proc->carry)
    {
        vm->print("FAILED\n");
        vm->print == &printw ? wait_input() : 0;
        return ;
    }
    proc_set_pc(vm, proc, vm->pc + target);
    vm->print("| Player %d \"%s\", ", proc->champ->id, proc->champ->name);
    vm->print("process %d ", proc->pid);
    vm->print("jumped to the address %u\n", proc->pc);
    vm->print == &printw ? wait_input() : 0;
}
