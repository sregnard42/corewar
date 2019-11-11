/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:46:00 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 11:44:51 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

void		champs_free(t_champs **champs_ptr)
{
	t_champs	*champs;

	if (!champs_ptr || !*champs_ptr)
		return ;
	champs = *champs_ptr;
	while (champs->first)
	{
		champs->cur = champs->first->next;
		champ_free(&champs->first);
		champs->first = champs->cur;
	}
	ft_memdel((void **)champs_ptr);
}
