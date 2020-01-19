/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 14:05:34 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 14:06:49 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			arena_init(t_vm *vm)
{
	unsigned int	nb_players;
	t_champ			*champ;

	nb_players = vm->champs.size;
	champ = vm->champs.first;
	while (champ)
	{
		champ->pos = (champ->id - 1) * (MEM_SIZE / nb_players);
		ft_memcpy(&vm->arena[champ->pos], &champ->content[champ->cursor],
				champ->prog_size);
		ft_memset(&vm->colors[champ->pos], champ->id, champ->prog_size);
		vm->champs.cur = champ;
		proc_new(vm);
		champ = champ->next;
	}
}
