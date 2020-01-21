/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:28:26 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 17:14:33 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** epure_line2() removes tabulations
*/

static void	epure_line2(char *line)
{
	int		i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\t')
			line[i] = ' ';
	}
}

/*
** manage_error() prints line if bonus -e is on.
** prints color if bonus -c is on.
** prints the apropriate error message.
** free and exit the program if bonus -q is off. (as -q lists all errors)
*/

void		manage_error(void *p, void (*f)(void *), char *line, char *msg)
{
	t_assembler	*tmp;

	(void)f;
	tmp = (t_assembler *)p;
	line ? epure_line2(line) : 0;
	if (tmp->bonus & BONUS_MANAGE_ERROR && line)
	{
		msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[35m", 5) : 0;
		ft_printf("line %d:\e[0m ", tmp->nb_line);
		msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[36m", 5) : 0;
		write(2, line, ft_strlen(line));
		msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[0m", 4) : 0;
		write(2, "\n\t", 2);
	}
	msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[1;31m", 7) : 0;
	msg ? write(2, "ERROR: ", 7) : 0;
	msg && tmp->bonus & BONUS_COLOR ? write(2, "\e[0m", 4) : 0;
	msg ? write(2, msg, ft_strlen(msg)) : 0;
	exit(EXIT_FAILURE);
}
