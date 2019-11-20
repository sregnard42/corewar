/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:28:12 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/20 17:22:31 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Swap two champions
*/

static void		champ_swap(t_champ *a, t_champ *b)
{
	t_champ	*a_prev;
	t_champ	*a_next;
	t_champ	*b_prev;
	t_champ	*b_next;

	a_prev = a->prev;
	a_next = a->next;
	b_prev = b->prev;
	b_next = b->next;
	ft_memswap(a, b, sizeof(t_champ));
	a->prev = a_prev;
	a->next = a_next;
	b->prev = b_prev;
	b->next = b_next;
}

/*
**			Find and return a champions by its ID
*/

static t_champ	*champ_find(t_champ *champ, unsigned int id)
{
	while (champ)
	{
		if (champ->id == id)
			return (champ);
		champ = champ->next;
	}
	return (NULL);
}

/*
**			Sort champions by their ID
*/

void			champs_sort(t_vm *vm)
{
	t_champs		*champs;
	t_champ			*champ;
	unsigned int	id;

	id = 1;
	champs = &vm->champs;
	champ = champs->first;
	while (champ)
	{
		if (champ->id != id)
			champ_swap(champ, champ_find(champ->next, id));
		++id;
		vm->champs.byId[champ->id] = champ;
		champ = champ->next;
	}
}

