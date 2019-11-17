/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:56:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/17 17:26:29 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// void	init_instruct(t_assembler, char *line)
// {
//
// }

void	parse_instruction(t_assembler *as, char *line)
{
	char	**tab;

	(void)as;
	clean_line(line);
	ft_printf("line = |%s|\n",line);
	if (!(tab = ft_strsplit(line, ' ')))
		return ;
	if (ft_strchr(tab[0], LABEL_CHAR) != NULL)
		ft_printf("%s is a label\n", tab[0]);
	ft_print_tab(tab);
	ft_putendl("----------------");
}
