/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:38:05 by sregnard          #+#    #+#             */
/*   Updated: 2019/12/10 14:38:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Gets the actual value of an argument depending on its type
**		REG_CODE returns the value inside of the registry
**		DIR_CODE returns the value as is
**		IND_CODE returns the value stocked at given address in the arena
**		Returns 0 if register is invalid, 1 in all other cases
*/

int		get_val(t_vm *vm, t_arg *arg, int *val, int modulo)
{
	t_process	*proc;

	proc = vm->procs.cur;
	ft_bzero(val, sizeof(int));
    if (arg->type == REG_CODE)
	{
		if (!is_reg(arg->val))
			return (0);
        regcpy(val, &proc->reg[arg->val], sizeof(int));
	}
    else if (arg->type == DIR_CODE)
        *val = arg->val;
    else if (arg->type == IND_CODE)
        arena_load(vm, vm->pc + (short int)arg->val % modulo, val, sizeof(int));
	return (1);
}

/*
**      Loads a value inside a registry
*/

void    load(t_vm *vm, int dst, int val)
{
	t_process   *proc;
    t_reg       *reg;

	proc = vm->procs.cur;
	if (!is_reg(dst))
	{
		vm->print("Register is invalid, nothing happens !\n");
		return ;
	}
	proc->carry = (val == 0);
    reg = &proc->reg[dst];
    ft_bzero(reg, REG_SIZE);
	regcpy(reg, &val, REG_SIZE);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("loaded value %d in r%d\n", val, dst);
	vm->print == &printw ? wait_input() : 0;
}