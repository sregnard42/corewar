/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:08:04 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/26 15:14:14 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes a register and a register / indirect. Copies the value of the
**		first argument in the second argument.
*/

void		op_st(void *vm_ptr)
{
	t_vm	*vm;
	t_args	*args;
	int		reg;
	int		addr;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	if (args->size < 2)
		return;
	reg = args->byId[0]->val;
	if (get_val(vm, args->byId[1], &addr, IDX_MOD) == 0)
		return;
	vm->print("st r%d, %d | ", reg, addr);
	store(vm, reg, vm->pc + addr);
}

/*
**		Takes a register and 2 indexes.
**		Copies the register value to the address of
**		the sum of the 2 indexes.
*/

void		op_sti(void *vm_ptr)
{
	t_vm	*vm;
	t_args	*args;
	int		reg;
	int		addr[2];

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	if (args->size < 3)
		return;
	reg = args->byId[0]->val;
	if (!(
        get_val(vm, args->byId[1], &addr[0], IDX_MOD) == 1 &&
        get_val(vm, args->byId[2], &addr[1], IDX_MOD) == 1))
		return ;
	vm->print("sti r%d, %d, %d | ", reg, addr[0], addr[1]);
	store(vm, reg, vm->pc + (addr[0] + addr[1]) % IDX_MOD);
}
