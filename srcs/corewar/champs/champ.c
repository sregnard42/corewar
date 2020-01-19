/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:41:07 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 15:17:31 by sregnard         ###   ########.fr       */
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
		ft_error(vm, &vm_free, "champ_new args\n");
	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_error(vm, &vm_free, "champ_new memalloc\n");
	champ->id = vm->flags & VM_NUMBER ? vm->number : 0;
	champ->list = &vm->champs;
	vm->flags &= ~VM_NUMBER;
	champs_add(vm, &vm->champs, champ);
	return (champ);
}
