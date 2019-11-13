/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:54:27 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/13 17:01:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Adds an existing label to an existing label list
*/

void		labels_add(t_vm *vm, t_labels *labels, t_label *label)
{
	if (!vm || !labels || !label)
		ft_error(vm, &free_all, "labels_add args\n");
	if (!labels->first)
	{
		labels->first = label;
		labels->last = label;
	}
	else
	{
		label->prev = labels->last;
		labels->last->next = label;
		labels->last = label;
	}
	labels->cur = label;
	++labels->size;
}

/*
**			Frees all labels in the list then the list itself
*/

void		labels_free(t_labels *labels)
{
	while (labels->first)
	{
		labels->cur = labels->first->next;
		label_free(&labels->first);
		labels->first = labels->cur;
	}
}

/*
**			Deletes a label from a list of labels
*/

void		labels_del(t_labels *labels, t_label **label_ptr)
{
	t_label	*label;

	label = *label_ptr;
	if (!(--labels->size))
		ft_bzero(labels, sizeof(t_labels));
	else if (labels->first == label)
	{
		labels->first = label->next;
		labels->first->prev = NULL;
	}
	else if (labels->last == label)
	{
		labels->last = labels->last->prev;
		labels->last->next = NULL;
	}
	else
	{
		label->prev->next = label->next;
		label->next->prev = label->prev;
	}
	label == labels->cur ? labels->cur = labels->first : 0;
	label_free(&label);
}
