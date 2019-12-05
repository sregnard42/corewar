/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/04 17:02:42 by lgaultie         ###   ########.fr       */
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
		if (!(as->epure_line = ft_strdup(as->line)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		i++; //pour savoir les lignes
		if (check_header(as) == FAIL)
			parse_instruction(as);
		ft_memdel((void*)&as->line);
		ft_memdel((void*)&as->epure_line);
	}
	if (i == 0)
		manage_error(as, &free_asm, as->epure_line, EMPTY_FILE);
	if (check_existing_labels(as) == FAIL)	//si je supprime ca le prog marche
	//alors que check_existing_labels fait manage_error!
		manage_error(as, &free_asm, as->epure_line, NO_EXIST_LABEL);
	get_prog_size(as);
	/////////////
	// print_instruc(as);
	// print_labels(as);
	// print_param_labels(as);
}
