/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:44:01 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/06 13:01:03 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Adds an existing command to an existing commands list
*/

void		cmds_add(t_vm *vm, t_commands *cmds, t_command *cmd)
{
	if (!vm || !cmds || !cmd)
		ft_error(vm, &free_all, "ERROR: cmds_add args\n");
	if (!cmds->first)
	{
		cmds->first = cmd;
		cmds->current = cmd;
		cmds->last = cmd;
	}
	else
	{
		cmds->last->next = cmd;
		cmds->last = cmd;
	}
	++cmds->size;
}

/*
**			Frees all commands in the list then the list itself
*/

void			cmds_free(t_commands **cmds_ptr)
{
	t_commands	*cmds;

	if (!cmds_ptr || !*cmds_ptr)
		return ;
	cmds = *cmds_ptr;
	while (cmds->first)
	{
		cmds->current = cmds->first->next;
		cmd_free(&cmds->first);
		cmds->first = cmds->current;
	}
	ft_memdel((void **)cmds_ptr);
}
