/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:54:29 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 13:03:11 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new label, which adds itself to a champion's label list
**			Takes an existing command as argument
*/

t_label		*label_new(t_vm *vm, t_command *cmd)
{
	t_label	*label;

	if (!vm || !vm->champs || !vm->champs->current ||
		!vm->champs->current->labels || !cmd)
		ft_error(vm, &free_all, "ERROR: label_new args\n");
	if (!(label = ft_memalloc(sizeof(t_label))))
		ft_error(vm, &free_all, "ERROR: label_new memalloc\n");
	labels_add(vm, vm->champs->current->labels, label);
	return (label);
}

/*
**			Frees a label
*/

void		label_free(t_label **label)
{
	ft_memdel((void **)label);
}
