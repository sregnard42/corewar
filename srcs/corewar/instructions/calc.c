/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:16:52 by cmouele           #+#    #+#             */
/*   Updated: 2019/12/09 20:43:56 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void calc(t_vm *vm, int opcode)
{
    t_process       *proc;
    t_args          *args;
    int				reg[3];
	int				val[2];

    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
	if (args->size < 3)
		return ;
    reg[0] = args->byId[0]->val;
    reg[1] = args->byId[1]->val;
    reg[2] = args->byId[2]->val;
	if (!(is_reg(reg[0]) && is_reg(reg[1]) && is_reg(reg[2])))
        return ;
	vm->print("P %4d | ", proc->pid);
    vm->print("%s r%d, r%d, r%d | ", op_names[opcode], reg[0], reg[1], reg[2]);
	ft_bzero(&val, sizeof(int) * 2);
	regcpy(&val[0], &proc->reg[reg[0]], sizeof(int));
	regcpy(&val[1], &proc->reg[reg[1]], sizeof(int));
    if (opcode == ADD)
	    load(vm, reg[2], val[0] + val[1]);
    else if (opcode == SUB)
	    load(vm, reg[2], val[0] - val[1]);
}

/*
**		Takes 3 registers, puts the sum of the 2 first registers in the third.
**      Modifies the carry.
*/

void	op_add(void *vm_ptr)
{
    calc(vm_ptr, ADD); 
}

/*
**		Takes 3 registers, puts the substraction of the 2 first registers in
**      the third. Modifies the carry.
*/

void	op_sub(void *vm_ptr)
{
    calc(vm_ptr, SUB); 
}