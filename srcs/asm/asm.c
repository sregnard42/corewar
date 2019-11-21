/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/21 18:05:22 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		open_file(t_assembler *as, char **argv)
{
	as->source_fd = open(argv[1], O_RDONLY);
	return (as->source_fd);
}

int		main(int argc, char **argv)
{
	t_assembler	as;

	if (argc > 2 || argc == 1)
	{
		ft_putstr("Usage: ./asm mychampion.s\n");
		return (0);
	}
	init_asm(&as);
	if (open_file(&as, argv) == -1)
		ft_error(&as, &free_asm, "Can't read source file ds\n");
	as.file_name_s = ft_strdup(argv[1]);
	parsing(&as);
	close(as.source_fd);
	// create_cor(&as);
	ft_error(&as, &free_asm, "");
	return (0);
}
