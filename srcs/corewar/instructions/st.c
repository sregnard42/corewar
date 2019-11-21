/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:08:04 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 12:08:05 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes a register and a register / indirect. Copies the value of the
**		first argument in the second argument.
*/

void	op_st(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	t_process		*proc;
	unsigned int	src;
	unsigned int	dst;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	proc = vm->procs.cur;
	src = args->first->val;
	dst = args->first->next->val;
	if (vm->verbose & V_OPERATIONS)
		ft_printf("st %u, %u | ", src, dst);
	/*ft_memcpy(vm->pc + (src % IDX_MOD), &src, sizeof(args->first->next->type));
	if (vm->verbose & V_OPERATIONS)
	{
		ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
		ft_printf("loaded value %u in register / parameter %u\n", src, dst);
	}*/
}

/*
**		Takes a register and 2 indexes, and copies the register to the address
**		of the sum of the 2 indexes.
*/

void	op_sti(void *vm_ptr)
{
    t_vm			*vm;
	t_args			*args;
	t_process		*proc;
	unsigned int	src;
	unsigned int	dst[2];
	unsigned int 	dst_sum;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	proc = vm->procs.cur;
	src = args->first->val;
	dst[0] = args->first->next->val;
	dst[1] = args->first->next->next->val;
	dst_sum = dst[0] + dst[1];

	if (vm->verbose & V_OPERATIONS)
		ft_printf("sti %u, %u, %u | ", src, dst[0], dst[1]);
	ft_memcpy(&dst_sum, proc->reg[src], REG_SIZE);
	if (vm->verbose & V_OPERATIONS)
	{
		ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
		ft_printf("loaded value %u in address %u\n", src, dst);
	}
}
