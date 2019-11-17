/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:02:50 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 10:02:52 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
