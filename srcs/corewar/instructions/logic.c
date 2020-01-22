/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:10:01 by cmouele           #+#    #+#             */
/*   Updated: 2020/01/19 15:41:22 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes two indexes and a register, applies a logical operation between
**      the first two parameters, and stores the result in the third one.
**      Modifies the carry.
*/

static void	logic(t_vm *vm, int opcode)
{
	t_args	*args;
	int		val[2];
	int		reg;

	args = &vm->procs.cur->args;
	if (args->size < 3)
		return ;
	reg = args->by_id[2]->val;
	if (!(
				get_val(vm, args->by_id[0], &val[0], IDX_MOD) == 1 &&
				get_val(vm, args->by_id[1], &val[1], IDX_MOD) == 1 &&
				is_reg(reg)))
		return ;
	vm->print("P %4d | ", vm->procs.cur->pid);
	vm->print("%s %d, %d, r%d | ", g_op_names[opcode], val[0], val[1], reg);
	if (opcode == AND)
		load(vm, reg, val[0] & val[1]);
	else if (opcode == OR)
		load(vm, reg, val[0] | val[1]);
	else if (opcode == XOR)
		load(vm, reg, val[0] ^ val[1]);
}

void		op_and(void *vm_ptr)
{
	logic(vm_ptr, AND);
}

void		op_or(void *vm_ptr)
{
	logic(vm_ptr, OR);
}

void		op_xor(void *vm_ptr)
{
	logic(vm_ptr, XOR);
}
