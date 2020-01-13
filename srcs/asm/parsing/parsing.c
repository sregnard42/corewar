/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/08 15:50:55 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** parsing() parse header, then if doesn't find .name or .comment, parse the
** line as an instruction. Then calls function to check if parameter label
** refers to existing label.
*/

void	parsing(t_assembler *as)
{
	while (get_next_line(as->s_fd, &as->line) == 1)
	{
		if (!(as->epure_line = ft_strdup(as->line)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		as->nb_line++;
		if (check_header(as) == FAIL)
			parse_instruction(as);
		ft_memdel((void*)&as->line);
		ft_memdel((void*)&as->epure_line);
	}
	if (as->nb_line == 0)
		manage_error(as, &free_asm, as->epure_line, EMPTY_FILE);
	check_existing_labels(as);

	get_prog_size(as);
	/////////////
	print_instruc(as);
	print_labels(as);
	// print_param_labels(as);
}
