/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:01:52 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 11:02:21 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Frees a label
*/

void		label_free(t_label **label)
{
    ft_memdel((void **)label);
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
