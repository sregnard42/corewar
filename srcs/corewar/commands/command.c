/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 21:46:22 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 11:47:30 by sregnard         ###   ########.fr       */
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

	if (!vm || !vm->champs.cur)
		ft_error(vm, &free_all, "cmd_new args\n");
	if (!(cmd = ft_memalloc(sizeof(t_command))))
		ft_error(vm, &free_all, "cmd_new memalloc\n");
	ft_bzero(&cmd->params, sizeof(t_params));
	cmd->champ = vm->champs.cur;
	cmd->list = &cmd->champ->cmds;
	cmds_add(vm, &vm->champs.cur->cmds, cmd);
	return (cmd);
}
