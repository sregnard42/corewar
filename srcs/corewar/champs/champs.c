/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/13 14:45:45 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Check if given ID has already been given to a champion
*/

static int	id_available(t_vm *vm, unsigned int id)
{
	t_champ	*champ;

	champ = vm->champs.first;
	while (champ)
	{
		if (champ->id == id)
			return (0);
		champ = champ->next;
	}
	return (1);
}

/*
**			Assign IDs to all champs that have no ID
**			Champs created with [-n number] option already have an ID
*/

void		champs_ids(t_vm *vm)
{
	t_champ			*champ;
	unsigned int	id;

	id = 1;
	champ = vm->champs.first;
	while (champ)
	{
		if (champ->id == 0)
		{
			while (!id_available(vm, id))
				++id;
			champ->id = id;
		}
		if (champ->id > vm->champs.size)
			ft_error(vm, &free_all, "Invalid ID.\n");
		champ = champ->next;
	}
}

/*
**			Adds an existing champion to an existing champion list
**			** This is a circular list **
*/

void		champs_add(t_vm *vm, t_champs *champs, t_champ *champ)
{
	if (!vm || !champs || !champ)
		ft_error(vm, &free_all, "champs_add args\n");
	if (!champs->first)
	{
		champs->first = champ;
		champs->last = champ;
	}
	else
	{
		champs->last->next = champ;
		champs->last = champ;
	}
	champs->cur = champ;
	++champs->size;
}
