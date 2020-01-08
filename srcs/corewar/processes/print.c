/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:31:42 by cmouele           #+#    #+#             */
/*   Updated: 2020/01/08 15:31:44 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void    proc_print(t_vm *vm, t_process *proc)
{
    int i;
    int val;

    i = 1;
    while (i <= REG_NUMBER)
    {
        val = 0;
        regcpy(&val, &proc->reg[i], sizeof(int));
        vm->print("[%d]", val);
        i++;
    }
    vm->print("\n");
}
