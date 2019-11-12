/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:50:01 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/12 15:51:11 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Frees a champion and everything it contains
*/

void		champ_free(t_champ **champ)
{
	labels_free(&(*champ)->labels);
	cmds_free(&(*champ)->cmds);
	procs_free(&(*champ)->procs);
	ft_memdel((void **)champ);
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
