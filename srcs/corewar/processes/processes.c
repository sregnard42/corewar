/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:23:10 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/13 16:51:15 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Adds an existing process to an existing processes list
*/

void		procs_add(t_vm *vm, t_processes *procs, t_process *proc)
{
	if (!vm || !procs || !proc)
		ft_error(vm, &free_all, "procs_add args\n");
	if (!procs->first)
	{
		procs->first = proc;
		procs->last = proc;
	}
	else
	{
		proc->prev = procs->last;
		procs->last->next = proc;
		procs->last = proc;
	}
	procs->cur = proc;
	++procs->size;
	++vm->champs.sum_procs;
}

/*
**			Deletes a process from a list of processes
*/

void		procs_del(t_vm *vm, t_processes *procs, t_process **proc_ptr)
{
	t_process	*proc;

	proc = *proc_ptr;
	--vm->champs.sum_procs;
	if (!(--procs->size))
		ft_bzero(procs, sizeof(t_processes));
	else if (procs->first == proc)
	{
		procs->first = proc->next;
		procs->first->prev = NULL;
	}
	else if (procs->last == proc)
	{
		procs->last = procs->last->prev;
		procs->last->next = NULL;
	}
	else
	{
		proc->prev->next = proc->next;
		proc->next->prev = proc->prev;
	}
	proc == procs->cur ? procs->cur = procs->first : 0;
	proc_free(&proc);
}
