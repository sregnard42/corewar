/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:16:52 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/27 17:01:34 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	op_calc(t_vm *vm, unsigned int dst, unsigned val)
{
	t_process *proc;

	proc = vm->procs.cur;
	proc->carry = (val == 0);
	ft_memcpy(&proc->reg[dst], &val, sizeof(t_reg));
	if (vm->verbose & V_OPERATIONS)
	{
		ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
		ft_printf("loaded value %u in register %u\n", val, dst);
	}
}

/*
**		Takes 3 registers, puts the sum of the 2 first registers in the third.
**      Modifies the carry.
*/

void	op_add(void *vm_ptr)
{
    t_vm            *vm;
    t_process       *proc;
    t_args          *args;
    unsigned int    reg[3];

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
	ft_bzero(&reg, sizeof(unsigned int) * 3);
    reg[0] = args->first->val;
    ft_memcpy(&reg[1], &proc->reg[args->first->next->val], sizeof(t_reg));
    ft_memcpy(&reg[2], &proc->reg[args->first->next->next->val], sizeof(t_reg));
    if (vm->verbose & V_OPERATIONS)
        ft_printf("add %u, %u, %u | ", reg[0], reg[1], reg[2]);
	op_calc(vm, reg[0], reg[1] + reg[2]);
}

/*
**		Comment
*/

void	op_sub(void *vm_ptr)
{
    t_vm            *vm;
    t_process       *proc;
    t_args          *args;
    unsigned int    reg[3];

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
	ft_bzero(&reg, sizeof(unsigned int) * 3);
    reg[0] = args->first->val;
    ft_memcpy(&reg[1], &proc->reg[args->first->next->val], sizeof(t_reg));
    ft_memcpy(&reg[2], &proc->reg[args->first->next->next->val], sizeof(t_reg));
    if (vm->verbose & V_OPERATIONS)
        ft_printf("sub %u, %u, %u | ", reg[0], reg[1], reg[2]);
	op_calc(vm, reg[0], reg[1] - reg[2]);
}
