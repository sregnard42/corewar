/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:10:01 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 12:10:02 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes two registers / directs / indirects, applies a logical AND
**      between the two, and stores the result in the third parameter that is a
**      register. Modifies the carry.
*/

void	op_and(void *vm_ptr)
{
    t_vm            *vm;
    t_process		*proc;
    t_args			*args;
	int				val[2];
    int             reg;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    reg = args->byId[2]->val;
    vm->print("and ");
    if (!(
        get_val(vm, args->byId[0], &val[0], IDX_MOD) == 1 &&
        get_val(vm, args->byId[1], &val[1], IDX_MOD) == 1 &&
        is_reg(reg)
        ))
    {
        vm->print("| Register is invalid, nothing happens !\n");
        return ;
    }
    vm->print("%d, %d, r%d | ", val[0], val[1], reg);
	load(vm, reg, val[0] & val[1]);
}

/*
**		Takes two registers / directs / indirects, applies a logical OR
**      between the two, and stores the result in the third parameter that is a
**      register. Modifies the carry.
*/

void	op_or(void *vm_ptr)
{
    t_vm            *vm;
    t_process		*proc;
    t_args			*args;
	int				val[2];
    int             reg;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    reg = args->byId[2]->val;
    vm->print("or ");
    if (!(
        get_val(vm, args->byId[0], &val[0], IDX_MOD) == 1 &&
        get_val(vm, args->byId[1], &val[1], IDX_MOD) == 1 &&
        is_reg(reg)
        ))
    {
        vm->print("| Register is invalid, nothing happens !\n");
        return ;
    }
    vm->print("%d, %d, r%d | ", val[0], val[1], reg);
	load(vm, reg, val[0] | val[1]);
}

/*
**		Takes two registers / directs / indirects, applies a logical XOR
**      between the two, and stores the result in the third parameter that is a
**      register. Modifies the carry.
*/

void	op_xor(void *vm_ptr)
{
    t_vm            *vm;
    t_process		*proc;
    t_args			*args;
	int				val[2];
    int             reg;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &vm->procs.cur->args;
    reg = args->byId[2]->val;
    vm->print("xor ");
    if (!(
        get_val(vm, args->byId[0], &val[0], IDX_MOD) == 1 &&
        get_val(vm, args->byId[1], &val[1], IDX_MOD) == 1 &&
        is_reg(reg)
        ))
    {
        vm->print("| Register is invalid, nothing happens !\n");
        return ;
    }
    vm->print("%d, %d, r%d | ", val[0], val[1], reg);
	load(vm, reg, val[0] ^ val[1]);
}
