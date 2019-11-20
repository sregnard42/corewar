/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:50:59 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/12 15:54:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Prints information about a champion
*/

void		champ_print(t_champ *champ)
{
	ft_printf("%-10s: %#x\n", "magic", champ->magic);
	ft_printf("%-10s: %s\n", "name", champ->name);
	ft_printf("%-10s: %dB\n", "prog_size", champ->prog_size);
	ft_printf("%-10s: %s\n", "comment", champ->comment);
	ft_printf("%-10s: %d\n", "ID", champ->id);
}

/*
**			Prints information about a list of champions
*/

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
