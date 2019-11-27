/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/27 14:24:35 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** parsing() if doesnt find .name or .comment, parse the line as a instruction
*/

void	parsing(t_assembler *as)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(as->s_fd, &line) == 1)
	{
		i++; //pour savoir les lignes
		if (check_header(as, line) == 0)
			parse_instruction(as, line);
		ft_memdel((void*)&line);
	}
	if (i == 0)
		ft_error(as, &free_asm, EMPTY_FILE);
	if (check_existing_labels(as) == -1)
		ft_error(as, &free_asm, NO_EXIST_LABEL);
	get_prog_size(as);
	/////////////
	// print_instruc(as);
	// print_labels(as);
	// print_param_labels(as);
	ft_printf("Parsing end\n\n");
	ft_printf("name = |%s|\ncomment = |%s|\n", as->header->name, as->header->comment);
}
