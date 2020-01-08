/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/08 12:12:01 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	open_file(t_assembler *as, char *argv)
{
	as->s_fd = open(argv, O_RDONLY);
	return (as->s_fd);
}

static int	check_file_type(char *argv)
{
	char		*s;

	if (!(s = ft_strrchr(argv, '.')) || ft_strcmp(s, ".s") != 0)
	{
		ft_putstr(NOT_S_FILE);
		return (0); // truc a faire $ manage error et leaks
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_assembler		as;
	unsigned int	flag;
	int				i;
	int				flag_on;

	i = 1;
	flag_on = 0;	// utile de faire un new int au lieu dutiliser flag dans le cas ou on fait ./asm -
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
			flag_on = 1;
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
		print_advices(&as);
		i++;
	}
	if (flag_on != 0 && i == 2)
		print_usage();
	free_asm(&as);
	return (0);
}
