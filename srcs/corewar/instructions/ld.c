/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:01:50 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/21 18:21:14 by sregnard         ###   ########.fr       */
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
	proc->carry = (src == 0);
	ft_memcpy(proc->reg[dst], &src, REG_SIZE);
	if (vm->verbose & V_OPERATIONS)
	{
		ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
		ft_printf("loaded value %u into R%u\n", src, dst);
	}
}

/*
**		Arg #1 : Value
**		Arg #2 : Registry number
*/

void	op_ld(void *vm_ptr)
{
	t_vm			*vm;
	t_args			*args;
	unsigned int	src;
	unsigned int	dst;

	vm = (t_vm *)vm_ptr;
	args = &vm->procs.cur->args;
	src = args->first->val;
	dst = args->first->next->val;
	if (vm->verbose & V_OPERATIONS)
		ft_printf("ld %u, %u | ", src, dst);
	load(vm, src, dst);
}

/*
**		Arg #1 & #2 : Add #1 to #2, which gives the address of the value
**		Arg #3 : Registry number
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
	if (vm->verbose & V_OPERATIONS)
		ft_printf("ldi %u, %u, %u | ", src[0], src[1], dst);
	load(vm, arena_get(vm, vm->pc + (src[0] + src[1]) % IDX_MOD), dst);
}

/*
**		Comment
*/

void	op_lld(void *vm_ptr)
{
    vm_ptr += 0;
    return ;
}

/*
**		Comment
*/

void	op_lldi(void *vm_ptr)
{
    vm_ptr += 0;
    return ;
}
