/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:41:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/12 15:53:14 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new champion, which adds itself to the VM's champion list
**			And initializes lists
*/

t_champ		*champ_new(t_vm *vm)
{
	t_champ	*champ;

	if (!vm)
		ft_error(vm, &free_all, "champ_new args\n");
	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_error(vm, &free_all, "champ_new memalloc\n");
	ft_bzero(&champ->labels, sizeof(t_labels));
	ft_bzero(&champ->cmds, sizeof(t_commands));
	ft_bzero(&champ->procs, sizeof(t_processes));
	champ->id = vm->flags & VM_NUMBER ? vm->number : 0;
	vm->flags &= ~VM_NUMBER;
	champs_add(vm, &vm->champs, champ);
	return (champ);
}

