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
**		Loads a value in a registry
**		Source is the value
**		Destination is the registry number
*/

static void	load(t_vm *vm, unsigned int src, unsigned int dst)
{
	t_process	*proc;

	proc = vm->procs.cur;
	proc->carry = (arena_get(vm, src) == 0);
	arena_load(vm, src, &proc->reg[dst], REG_SIZE);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("loaded value %u into R%u\n", arena_get(vm, src), dst);
	vm->print == &printw ? wait_input() : 0;
}

/*
**		Takes a direct / indirect, and a register. Charges the value of the
**		direct / indirect in the register. Modifies the carry.
*/

void	op_ld(void *vm_ptr)
{
	t_vm			*vm;
	t_process		*proc;
	t_args			*args;
	int				src;
	int				dst;

	vm = (t_vm *)vm_ptr;
	proc = vm->procs.cur;
	args = &vm->procs.cur->args;
	src = args->byId[0]->val;
	dst = args->byId[1]->val;
	if (args->byId[0]->type == DIR_CODE)
	{
		vm->print("ld %d, %d | ", src, dst);
		regcpy(&args->first->proc->reg[dst], &src, DIR_SIZE);
		vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
		vm->print("loaded value %u into R%u\n", src, dst);
	}
	else
	{
		vm->print("ld %%%d, %d | ", src, dst);
		load(vm, vm->pc + src % IDX_MOD, dst);
	}
}

/*
**		Takes and 2 directs and a register. Puts the value of the sum of the 2
**		directs in the register.
*/

void	op_ldi(void *vm_ptr)
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
	vm->print("ldi %u, %u, %u | ", src[0], src[1], dst);
	load(vm, vm->pc + (src[0] + src[1]) % IDX_MOD, dst);
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
