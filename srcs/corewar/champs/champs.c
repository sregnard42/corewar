/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/12 15:39:29 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

/*
**			Frees all champions in the list then the list itself
*/

void		champs_free(t_champs *champs)
{
	if (!champs)
		return ;
	while (champs->first)
	{
		champs->cur = champs->first->next;
		champ_free(&champs->first);
		champs->first = champs->cur;
	}
}

void		champs_print(t_champs *champs)
{
	t_champ	*champ;
	int		i;

	if (!champs->size)
		return ;
	i = 1;
	champ = champs->first;
	while (champ)
	{
		ft_printf("\n##### CHAMPION NO. %d #####\n", i++);
		champ_print(champ);
		champ = champ->next;
	}
}
