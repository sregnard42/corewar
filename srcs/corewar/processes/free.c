/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:02:50 by cmouele           #+#    #+#             */
/*   Updated: 2020/01/19 15:47:47 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Frees a process
*/

void		proc_free(t_process **proc)
{
	ft_memdel((void **)proc);
}

/*
**			Frees all processes in the list then the list itself
*/

void		procs_free(t_processes *procs)
{
	while (procs->first)
	{
		procs->cur = procs->first->next;
		proc_free(&procs->first);
		procs->first = procs->cur;
	}
}
