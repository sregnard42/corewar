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
**      Takes a register and a register / indirect. Copies the value of the
**      first argument to the address of the second argument.
*/

void    store(t_vm *vm, unsigned int src, unsigned int dst)
{
    t_process		*proc;

    proc = vm->procs.cur;
    ft_memcpy(&(vm->arena[dst]), &(proc->reg[src]), REG_SIZE); //ft_arenacpy
    if (vm->verbose & V_OPERATIONS)
    {
        ft_printf("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
        ft_printf("stored value %u in address %u\n", proc->reg[src], dst);
    }
}

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
	dst = 0;
    if (args->first->next->type == REG_CODE)
        ft_memcpy(&dst, &(proc->reg[args->first->next->val]), REG_SIZE);
    else
    	dst = args->first->next->val;
	if (vm->verbose & V_OPERATIONS)
		ft_printf("st %u, %u | ", src, dst);
	store(vm, src, vm->pc + dst % IDX_MOD);
}

/*
**		Takes a register and 2 indexes, and copies the register to the address
**		of the sum of the 2 indexes.
*/

void	op_sti(void *vm_ptr)
{
    t_vm			*vm;
    t_process		*proc;
	t_args			*args;
	unsigned int	src;
	unsigned int	dst[2];

	vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
	args = &vm->procs.cur->args;
	src = args->first->val;
    ft_bzero(&dst, sizeof(dst));
	if (args->first->next->type == REG_CODE)
        ft_memcpy(&dst[0], &(proc->reg[args->first->next->val]), REG_SIZE);
    else
        dst[0] = args->first->next->val;
    if (args->first->next->next->type == REG_CODE)
        ft_memcpy(&dst[1], &(proc->reg[args->first->next->next->val]), REG_SIZE);
	else
        dst[1] = args->first->next->next->val;
	if (vm->verbose & V_OPERATIONS)
		ft_printf("sti %u, %u, %u | ", src, dst[0], dst[1]);
	store(vm, src, vm->pc + ((dst[0] + dst[1]) % IDX_MOD));
}
