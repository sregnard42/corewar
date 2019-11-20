/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:33:42 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 11:33:43 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**		Keeps a process alive and tells that a player is alive.
*/

void    op_live(void *vm_ptr)
{
    t_vm    *vm;

    vm = (t_vm *)vm_ptr;
    vm->champs.cur->procs.cur->live = 1;
    ft_printf("A process shows that player %u (%s) is alive\n", vm->champs.cur->id, vm->champs.cur->name);
}
