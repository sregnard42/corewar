/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:28:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/04 15:15:05 by lgaultie         ###   ########.fr       */
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
	msg && tmp->bonus & BONUS_COLOR ? ft_putstr("\033[1;31m") : 0;
	msg ? write(2, "ERROR: ", 7) : 0;
	msg && tmp->bonus & BONUS_COLOR ? ft_putstr("\033[0m") : 0;
	msg ? write(2, msg, ft_strlen(msg)) : 0;
	if (f && p)
		f(p);
	exit(EXIT_FAILURE);
}
