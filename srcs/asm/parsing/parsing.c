/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/21 17:44:51 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// Marche si label n'as pas de ':' à la fin
//elle est appelée nul part cette fonction wtf?

// void	check_label(t_assembler *as, char *label)
// {
// 	int	i;
//
// 	i = 0;
// 	while (label[i] != '\0')
// 	{
// 		if (ft_strchr(LABEL_CHARS, label[i]) == NULL)
// 			ft_error(as, &free_asm, "Label with a non LABEL_CHARS.\n");
// 		i = i + 1;
// 	}
// }

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

	/////////////
	print_instruc(as);
	print_labels(as);
	print_param_labels(as);
	ft_printf("Parsing end\n\n");
	ft_printf("name = |%s|\ncomment = |%s|\n", as->header->name, as->header->comment);
}
