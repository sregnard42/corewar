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
**      Loads a value inside a registry
*/

void    load(t_vm *vm, int dst, int val)
{
	t_process   *proc;
    t_reg       *reg;

	proc = vm->procs.cur;
	proc->carry = (val == 0);
    reg = &proc->reg[dst];
    ft_bzero(reg, REG_SIZE);
	regcpy(reg, &val, REG_SIZE);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("loaded value %d in r%d\n", val, dst);
	vm->print == &printw ? wait_input() : 0;
}