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

/*
**		Takes an indirect. Jumps to the address of the index if carry == 1.
*/

void	op_zjmp(void *vm_ptr)
{
    t_vm			*vm;
    t_process       *proc;
    t_args			*args;
    unsigned int	src;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    src = args->first->val;
    if (proc->carry == 1)
        proc->pc += src;
    if (vm->verbose & V_OPERATIONS)
    {
        ft_printf("zjmp %u | ", src);
        ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
        ft_printf("jumped to the address %u\n", proc->pc);
    }
}
