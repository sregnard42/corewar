/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:41:07 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 15:41:47 by sregnard         ###   ########.fr       */
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
		ft_error(vm, &free_all, "champ_new args\n");
	if (!(champ = ft_memalloc(sizeof(t_champ))))
		ft_error(vm, &free_all, "champ_new memalloc\n");
	champ->labels = ft_memalloc(sizeof(t_labels));
	champ->cmds = ft_memalloc(sizeof(t_commands));
	champ->procs = ft_memalloc(sizeof(t_processes));
	if (!(champ->labels && champ->cmds && champ->procs))
		ft_error(vm, &free_all, "champ_new memalloc\n");
	champs_add(vm, vm->champs, champ);
	return (champ);
}

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

void		champ_print(t_champ *champ)
{
	ft_printf("%-10s: %#x\n", "magic", champ->magic);
	ft_printf("%-10s: %s\n", "name", champ->name);
	ft_printf("%-10s: %dB\n", "prog_size", champ->prog_size);
	ft_printf("%-10s: %s\n", "comment", champ->comment);
}
