/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:41:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/04 15:13:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Create a new champion, which adds itself to the VM's champion list
*/

t_champ		*champ_new(t_vm *vm)
{
	t_champ	*champ;

	if (!vm)
		ft_error(&vm, &free_all, "ERROR: champ_new args\n");
	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_error(&vm, &free_all, "ERROR: champ_new memalloc\n");
	champs_add(vm, vm->champs, champ);
	return (champ);
}
