/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 22:23:10 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/06 18:27:02 by sregnard         ###   ########.fr       */
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
		procs->cur = proc;
		procs->last = proc;
	}
	else
	{
		procs->last->next = proc;
		procs->last = proc;
	}
	++procs->size;
}

/*
**			Frees all processes in the list then the list itself
*/

void		procs_free(t_processes **procs_ptr)
{
	t_processes	*procs;

	if (!procs_ptr || !*procs_ptr)
		return ;
	procs = *procs_ptr;
	while (procs->first)
	{
		procs->cur = procs->first->next;
		proc_free(&procs->first);
		procs->first = procs->cur;
	}
	ft_memdel((void **)procs_ptr);
}
