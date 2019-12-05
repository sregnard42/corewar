/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:28:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/04 17:07:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void manage_error(void *p, void (*f)(void *), char *line, char *msg)
{
	t_assembler	*tmp;

	tmp = (t_assembler *)p;
	if (tmp->bonus & BONUS_MANAGE_ERROR && line)
	{
		msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[36m", 5) : 0;
		write(2, line, ft_strlen(line));
		msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[0m", 4) : 0;
		write(2, "\n\t", 2);
	}
	msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[1;31m", 7) : 0;
	msg ? write(2, "ERROR: ", 7) : 0;
	msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[0m", 4) : 0;
	msg ? write(2, msg, ft_strlen(msg)) : 0;
	if (f && p)
		f(p);
	exit(EXIT_FAILURE);
}
