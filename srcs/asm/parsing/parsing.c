/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/04 15:24:47 by lgaultie         ###   ########.fr       */
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
	int		i;

	i = 0;
	while (get_next_line(as->s_fd, &as->line) == 1)
	{
		i++; //pour savoir les lignes
		if (check_header(as) == FAIL)
			parse_instruction(as);
		ft_memdel((void*)&as->line);
	}
	if (i == 0)
		manage_error(as, &free_asm, as->epure_line, EMPTY_FILE);
	if (check_existing_labels(as) == FAIL)
		manage_error(as, &free_asm, as->epure_line, NO_EXIST_LABEL);
	get_prog_size(as);
	/////////////
	print_instruc(as);
	// print_labels(as);
	// print_param_labels(as);
	ft_printf("Parsing end\n\n");
	ft_printf("name = |%s|\ncomment = |%s|\n", as->header->name, as->header->comment);
}
