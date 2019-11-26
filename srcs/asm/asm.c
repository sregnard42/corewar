/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/26 13:41:15 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		open_file(t_assembler *as, char *argv)
{
	as->source_fd = open(argv, O_RDONLY);
	return (as->source_fd);
}

int		check_file_type(char *argv)
{
	char		*s;

	if (!(s = ft_strchr(argv, '.')) || ft_strcmp(s, ".s") != 0)
	{
		ft_putstr(NOT_S_FILE);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_assembler	as;
	int			i;

	i = 1;
	if (argc == 1)
	{
		ft_putstr("Usage: ./asm [-help] mychampion1.s mychampion2.s\n");
		return (0);
	}
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-help") == 0)
		{
			ft_putstr("Usage: -error pour changer les trucs en errors, etc les bonus\n");
				return (0);
		}
		if (check_file_type(argv[i]) == 0)
			return (0);
		init_asm(&as);
		if (open_file(&as, argv[i]) == -1)
			ft_error(&as, &free_asm, CANT_READ);
		as.file_name_s = ft_strdup(argv[i]);
		parsing(&as);
		close(as.source_fd);
		create_cor(&as);
		i++;
	}
	free_asm(&as);
	return (0);
}
