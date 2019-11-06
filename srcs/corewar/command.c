/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:46:22 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/06 12:32:33 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new command, which adds itself to a champion's commands
**			list
*/

t_command	*cmd_new(t_vm *vm)
{
	t_command	*cmd;

	if (!vm || !vm->champs || !vm->champs->current ||
		!vm->champs->current->cmds)
		ft_error(vm, &free_all, "ERROR: cmd_new args\n");
	if (!(cmd = ft_memalloc(sizeof(t_command))))
		ft_error(vm, &free_all, "ERROR: cmd_new memalloc\n");
	cmds_add(vm, vm->champs->current->cmds, cmd);
	return (cmd);
}

/*
**			Frees a command
*/

void		cmd_free(t_command **cmd)
{
	ft_memdel((void **)cmd);
}
