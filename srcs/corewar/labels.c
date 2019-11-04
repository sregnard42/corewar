/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:54:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/04 23:55:13 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Adds an existing label to an existing label list
*/

void		labels_add(t_vm *vm, t_labels *labels, t_label *label)
{
	if (!vm || !labels || !label)
		ft_error(vm, &free_all, "ERROR: labels_add args\n");
	if (!labels->first)
	{
		labels->first = label;
		labels->current = label;
		labels->last = label;
	}
	else
	{
		labels->last->next = label;
		labels->last = label;
	}
	++labels->size;
}
