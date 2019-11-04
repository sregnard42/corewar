/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:21:55 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/04 23:54:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new process, which adds itself to a champion's processes
**			list
*/

t_process	*proc_new(t_vm *vm)
{
	t_process	*proc;

	if (!vm || !vm->champs || !vm->champs->current ||
		!vm->champs->current->procs)
		ft_error(vm, &free_all, "ERROR: proc_new args\n");
	if (!(proc = ft_memalloc(sizeof(t_process))))
		ft_error(vm, &free_all, "ERROR: proc_new memalloc\n");
	procs_add(vm, vm->champs->current->procs, proc);
	return (proc);
}
