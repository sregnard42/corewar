/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:23:10 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/04 23:55:24 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Adds an existing process to an existing processes list
*/

void		procs_add(t_vm *vm, t_processes *procs, t_process *proc)
{
	if (!vm || !procs || !proc)
		ft_error(vm, &free_all, "ERROR: procs_add args\n");
	if (!procs->first)
	{
		procs->first = proc;
		procs->current = proc;
		procs->last = proc;
	}
	else
	{
		procs->last->next = proc;
		procs->last = proc;
	}
	++procs->size;
}
