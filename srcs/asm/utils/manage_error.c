/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:28:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/04 14:16:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void manage_error(void *p, void (*f)(void *), char *line, char *msg)
{
	t_assembler	*tmp;

	tmp = (t_assembler *)p;
	if (tmp->bonus & BONUS_MANAGE_ERROR && line)
	{
		write(2, line, ft_strlen(line));
		write(2, "\n\t", 2);
	}
	ft_error(p, f, msg);
}
