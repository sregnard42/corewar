/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:42:31 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/22 12:45:59 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** write_neg_label() goes through all instructions starting from
** the BEGINNING to find label, if it does, writes the parameter with negative
** value.
*/

static void		write_neg_label(t_assembler *as, t_instruc *now, char *param,
			int res)
{
	t_instruc		*instruc;
	t_same_label	*label;

	instruc = as->instruc;
	res = 0;
	while (instruc)
	{
		label = instruc->label;
		while (label)
		{
			if (label && ft_strcmp(label->name, param) == 0)
			{
				while (instruc)
				{
					if (instruc == now)
						write_neg_number(as, res, now->direct_size);
					res += instruc->size;
					instruc = instruc->next;
				}
				return ;
			}
			label = label->next;
		}
		instruc = instruc->next;
	}
}

/*
** write_label() goes through the instructions BEHIND our current instruction
** to find the label reffering in the parameter. If finds the label, write the
** parameter in big endian.
** If it doesn't find the label, goes through all instructions starting from
** the BEGINNING to find it, if it does, writes the parameter with negative
** value.
*/

void			write_label(t_assembler *as, t_instruc *now, char *param)
{
	int				res;
	t_instruc		*instruc;
	t_same_label	*label;

	instruc = now;
	res = 0;
	param++;
	while (instruc)
	{
		label = instruc->label;
		while (label)
		{
			if (label && ft_strcmp(label->name, param) == 0)
			{
				write_big_endian(as, res, now->direct_size);
				return ;
			}
			label = label->next;
		}
		res += instruc->size;
		instruc = instruc->next;
	}
	write_neg_label(as, now, param, res);
}
