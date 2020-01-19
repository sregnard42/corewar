/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:29:39 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/19 15:54:13 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** read_function() parse header, then if doesn't find .name or .comment, parse
** the line as an instruction. Then calls function to check if parameter label
** refers to existing label.
*/

void	read_function(t_assembler *as)
{
	while (get_next_line(as->s_fd, &as->line) == 1)
	{
		if (!(as->epure_line = ft_strdup(as->line)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		as->nb_line++;
		if (check_header(as) == FAIL)
			analyse_instruction(as);
		// ft_printf("after as->line = %s\n", as->line);
		ft_memdel((void*)&as->line);
		ft_memdel((void*)&as->epure_line);
	}
	if (as->nb_line == 0)
		manage_error(as, &free_asm, as->epure_line, EMPTY_FILE);
	check_existing_labels(as);
	get_prog_size(as);
}
