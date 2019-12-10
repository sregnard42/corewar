/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:01:50 by cmouele           #+#    #+#             */
/*   Updated: 2019/12/09 20:45:52 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes a direct / indirect, and a register. Loads the value of the
**		direct / indirect in the register. Modifies the carry.
*/

void	op_ld(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	int				val;
	int				reg;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	get_val(vm, args->byId[0], &val, IDX_MOD);
	reg = args->byId[1]->val;
	if (args->byId[0]->type == IND_CODE)
		vm->print("ld %d, %d | ", (short int)args->byId[0]->val, reg);
	else
		vm->print("ld %%%d, %d | ", val, reg);
	load(vm, reg, val);
}

/*
**		Takes and 2 directs and a register. Puts the value of the sum of the 2
**		directs in the register.
*/

void	op_ldi(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	int				val[2];
	int				reg;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	val[0] = args->byId[0]->val;
	val[1] = args->byId[1]->val;
	reg = args->byId[2]->val;
}

/*
**		Same as ld() except for the addressing, where there is no IDX_MOD.
*/

void	op_lld(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	unsigned int	src;
	unsigned int	dst;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	src = args->first->val;
	dst = args->first->next->val;
	vm->print("lld %u, %u | ", src, dst);
	load(vm, vm->pc + src, dst);
}

/*
**		Same as ldi() except for the addressing, where there is no IDX_MOD.
*/

void	op_lldi(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	unsigned int	src[2];
	unsigned int	dst;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	src[0] = args->first->val;
	src[1] = args->first->next->val;
	dst = args->first->next->next->val;
	vm_print(vm, V_OPERATIONS)("lldi %u, %u, %u | ", src[0], src[1], dst);
	load(vm, vm->pc + src[0] + src[1], dst);
}
