/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:00 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 15:17:46 by sregnard         ###   ########.fr       */
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
			ft_error(vm, &vm_free, "Invalid ID.\n");
		champ = champ->next;
	}
}

/*
**			Adds an existing champion to an existing champion list
*/

void		champs_add(t_vm *vm, t_champs *champs, t_champ *champ)
{
	if (!vm || !champs || !champ)
		ft_error(vm, &vm_free, "champs_add args\n");
	if (!champs->first)
	{
		champs->first = champ;
		champs->last = champ;
	}
	else
	{
		champ->prev = champs->last;
		champs->last->next = champ;
		champs->last = champ;
	}
	champs->cur = champ;
	++champs->size;
}

/*
**			Deletes a champion from a list of champions
*/

void		champs_del(t_champs *champs, t_champ **champ_ptr)
{
	t_champ	*champ;

	champ = *champ_ptr;
	if (!(--champs->size))
		ft_bzero(champs, sizeof(t_champs));
	else if (champs->first == champ)
	{
		champs->first = champ->next;
		champs->first->prev = NULL;
	}
	else if (champs->last == champ)
	{
		champs->last = champs->last->prev;
		champs->last->next = NULL;
	}
	else
	{
		champ->prev->next = champ->next;
		champ->next->prev = champ->prev;
	}
	champ == champs->cur ? champs->cur = champs->first : 0;
	champ_free(&champ);
}
