/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 12:12:47 by cmouele           #+#    #+#             */
/*   Updated: 2019/12/01 13:58:50 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Takes a register as an ASCII, and displays it on the standard output.
*/

void	op_aff(void *vm_ptr)
{
    t_vm			*vm;
    t_args          *args;
    unsigned int    val;

    vm = (t_vm *)vm_ptr;
    args = &vm->procs.cur->args;
    val = args->first->val % 256;
    vm->print("%c\n", val);
}
