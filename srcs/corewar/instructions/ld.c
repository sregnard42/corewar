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
	if (args->size < 2)
		return ;
	get_val(vm, args->byId[0], &val, IDX_MOD);
	reg = args->byId[1]->val;
	if (args->byId[0]->type == IND_CODE)
		vm->print("ld %d, r%d | ", (short int)args->byId[0]->val, reg);
	else
		vm->print("ld %%%d, r%d | ", val, reg);
	load(vm, reg, val);
}

/*
**		Takes 2 indexes and a register. Puts the value of the sum of the 2
**		directs in the register.
*/

void	op_ldi(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	int				val[3];
	int				reg;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	if (args->size < 3)
		return ;
	get_val(vm, args->byId[0], &val[0], IDX_MOD);
	get_val(vm, args->byId[1], &val[1], IDX_MOD);
	arena_load(vm, val[0] + val[1], &val[2], sizeof(int));
	reg = args->byId[2]->val;
	vm->print("ldi %%%d, %%%d, r%d | ", val[0], val[1], reg);
	load(vm, reg, val[2]);
}

/*
**		Same as ld() except for the addressing, where there is no IDX_MOD.
*/

void	op_lld(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	int				val;
	int				reg;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	if (args->size < 2)
		return ;
	get_val(vm, args->byId[0], &val, 1);
	reg = args->byId[1]->val;
	if (args->byId[0]->type == IND_CODE)
		vm->print("lld %d, r%d | ", (short int)args->byId[0]->val, reg);
	else
		vm->print("lld %%%d, r%d | ", val, reg);
	load(vm, reg, val);
}

/*
**		Same as ldi() except for the addressing, where there is no IDX_MOD.
*/

void	op_lldi(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	int				val[3];
	int				reg;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	if (args->size < 3)
		return ;
	get_val(vm, args->byId[0], &val[0], 1);
	get_val(vm, args->byId[1], &val[1], 1);
	arena_load(vm, val[0] + val[1], &val[2], sizeof(int));
	reg = args->byId[2]->val;
	vm->print("lldi %%%d, %%%d, r%d | ", val[0], val[1], reg);
	load(vm, reg, val[2]);
}
