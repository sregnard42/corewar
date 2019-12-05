/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/05 15:56:15 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	open_file(t_assembler *as, char *argv)
{
	as->s_fd = open(argv, O_RDONLY);
	return (as->s_fd);
}

int			check_file_type(char *argv)
{
	char		*s;

	if (!(s = ft_strchr(argv, '.')) || ft_strcmp(s, ".s") != 0)
	{
		ft_putstr(NOT_S_FILE);
		return (0); // truc a faire $ manage error et leaks
	}
	return (1);
}

void		print_usage()
{
	ft_putstr("\e[32mUsage:\e[0m	./asm \e[35m[-hfqec]\e[0m mychampion1.s\n");
	ft_putstr("\e[35mHelp\e[0m on program and bonus: ./asm \e[35m-h\e[0m\n");
}

int			main(int argc, char **argv)
{
	t_assembler		as;
	unsigned int	flag;
	int				i;

	i = 1;
	if (argc == 1)
	{
		print_usage();
		return (0);
	}
	init_bonus(&flag, argv);
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			++i;
			continue;
		}
		if (check_file_type(argv[i]) == 0)
			return (0);
		init_asm(&as, flag);
		if (open_file(&as, argv[i]) == -1)
			manage_error(&as, &free_asm, NULL, CANT_READ);
		if (!(as.file_name_s = ft_strdup(argv[i])))
		{
			// faire les free necessaires
			return(0);
		}
		parsing(&as);
		close(as.s_fd);
		create_cor(&as);
		i++;
	}
	free_asm(&as);
	return (0);
}
