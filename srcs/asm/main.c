/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/09 17:24:51 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		open_file(t_assembler *assembler, char **argv)
{
	assembler->source_fd = open(argv[1], O_RDONLY);
	return (assembler->source_fd);
	// Parsing

	// while (ret != 0)
	// {
	// 	ret = get_next_line(fd, &line);
	// 	if (ret != 0)
	// 	{
	// 		if (line[0] == '.')			//parsing avec aucune verif
	// 			parse_name_comment(fd, line);
	// 		ft_memdel((void*)&line);
	// 	}
	// }
}

int		main(int argc, char **argv)
{
	t_assembler	assembler;

	if (argc > 2 || argc == 1)
	{
		ft_putstr("Usage: ./asm mychampion.s\n");
		return (0);
	}
	init_asm(&assembler); // Initialisation de la structure asm
	if (open_file(&assembler, argv) == -1)
		ft_error(&assembler, NULL, "Can't read source file ds\n");
	assembler.file_name_s = argv[1];
	// parsing(&assembler); // Quelque chose ne marche pas dans parsing, en lien avec
	// gnl, il me renvoit un chiffre bizzare, à check
	close(assembler.source_fd);
	// creat_cor(&assembler);
	return (0);
}
