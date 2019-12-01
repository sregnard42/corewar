/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:12:47 by cmouele           #+#    #+#             */
/*   Updated: 2019/12/01 13:58:50 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes a register as an ASCII, and displays it on the standard output.
*/

void	op_aff(void *vm_ptr)
{
    t_vm			*vm;
    t_args          *args;
    t_process		*proc;
    unsigned int    reg;
    unsigned int    val;

    vm = (t_vm *)vm_ptr;
    args = &vm->procs.cur->args;
    proc = vm->procs.cur;
    reg = args->first->val;
    val = reg % 256;
    if (vm->verbose & V_OPERATIONS)
    {
        vm->print("aff %u | ", val);
        vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
        vm->print("displayed character %c\n", val);
    }
    vm_print(vm, 0)("%c\n", val);
}
