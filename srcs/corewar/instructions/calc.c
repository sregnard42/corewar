/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:16:52 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 12:16:54 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes 3 registers, puts the sum of the 2 first registers in the third.
**      Modifies the carry.
*/

void	op_add(void *vm_ptr)
{
    t_vm            *vm;
    t_process       *proc;
    t_args          *args;
    unsigned int    reg1;
    unsigned int    reg2;
    unsigned int    reg3;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    reg1 = args->first->val;
    reg2 = args->first->next->val;
    reg3 = args->first->next->next->val;
    ft_memcpy(&reg3, reg1 + reg2, REG_SIZE);
    if (vm->verbose & V_OPERATIONS)
    {
        ft_printf("add %u, %u, %u | ", reg1, reg2, reg3);
        ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
        ft_printf("stored value %u into R%u\n", reg1 + reg2, reg3);
    }
    // proc->carry = ;
}

/*
**		Comment
*/

void	op_sub(void *vm_ptr)
{
    vm_ptr += 0;
    return ;
}
