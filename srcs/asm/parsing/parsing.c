/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/26 11:54:09 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** parsing() if doesnt find .name or .comment, parse the line as a instruction
*/

void	parsing(t_assembler *as)
{
	int		fd;
	char	*line;

	fd = as->source_fd;
	while (get_next_line(fd, &line) == 1)
	{
		if (check_header(as, line) == 0)
			parse_instruction(as, line);
		ft_memdel((void*)&line);
	}
	if (check_existing_labels(as) == -1)
		ft_error(as, &free_asm, "Label in argument doesn't exist.\n");
	get_prog_size(as);
	/////////////
	// print_instruc(as);
	// print_labels(as);
	// print_param_labels(as);
	ft_printf("Parsing end\n\n");
	ft_printf("name = |%s|\ncomment = |%s|\n", as->header->name, as->header->comment);
}
