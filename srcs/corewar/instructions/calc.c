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

static void	calc(t_vm *vm, unsigned int dst, unsigned val)
{
	t_process *proc;

	proc = vm->procs.cur;
	proc->carry = (val == 0);
	ft_memcpy(&proc->reg[dst], &val, sizeof(t_reg));
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("loaded value %u in register %u\n", val, dst);
	vm->print == &printw ? wait_input() : 0;
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
    ft_memcpy(&reg[0], &proc->reg[args->first->val], sizeof(t_reg));
    ft_memcpy(&reg[1], &proc->reg[args->first->next->val], sizeof(t_reg));
    reg[2] = args->first->next->next->val;
    vm->print("add r%u, r%u, r%u | ",
    args->first->next->val, args->first->next->next->val, reg[2]);
	op_calc(vm, reg[2], reg[0] + reg[1]);
}

/*
**		Takes 3 registers, puts the substraction of the 2 first registers in
**      the third. Modifies the carry.
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
    ft_memcpy(&reg[0], &proc->reg[args->first->val], sizeof(t_reg));
    ft_memcpy(&reg[1], &proc->reg[args->first->next->val], sizeof(t_reg));
    reg[2] = args->first->next->next->val;
    vm->print("sub r%u, r%u, r%u | ",
    args->first->val, args->first->next->val, reg[2]);
	op_calc(vm, reg[2], reg[0] - reg[1]);
}
