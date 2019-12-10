/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:12:47 by cmouele           #+#    #+#             */
/*   Updated: 2019/12/09 18:54:22 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes a register ID as a parameter.
**      Displays its value as ASCII character on the standard output.
*/

void	op_aff(void *vm_ptr)
{
    t_vm			*vm;
    t_process		*proc;
    t_args          *args;
    int             reg;
    unsigned char   c;

    vm = (t_vm *)vm_ptr;
    proc = vm->procs.cur;
    args = &proc->args;
	if (args->size < 1)
		return ;
    reg = args->first->val;
    if (!is_reg(reg))
        return ;
    vm->print("aff r%d | ", reg);
	regcpy(&c, &proc->reg[reg], sizeof(unsigned char));
    vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
    vm->print("displayed character %c\n", c);
    vm_print(vm, 0)("%c\n", c);
    vm->print == &printw ? wait_input() : 0;
}
