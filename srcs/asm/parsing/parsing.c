/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/04 13:51:38 by lgaultie         ###   ########.fr       */
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
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(as->s_fd, &line) == 1)
	{
		i++; //pour savoir les lignes
		if (check_header(as, line) == FAIL)
			parse_instruction(as, line);
		ft_memdel((void*)&line);
	}
	if (i == 0)
		manage_error(as, &free_asm, line, EMPTY_FILE);
		// ft_error(as, &free_asm, EMPTY_FILE);
	if (check_existing_labels(as) == FAIL)
		ft_error(as, &free_asm, NO_EXIST_LABEL);
	get_prog_size(as);
	/////////////
	print_instruc(as);
	// print_labels(as);
	// print_param_labels(as);
	ft_printf("Parsing end\n\n");
	ft_printf("name = |%s|\ncomment = |%s|\n", as->header->name, as->header->comment);
}
