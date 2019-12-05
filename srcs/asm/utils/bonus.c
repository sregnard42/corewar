/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:21:00 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/05 17:06:14 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_help()
{
	ft_putstr("\e[32mUsage:\n\t\e[0m ./asm \e[36m[-hfqec]\e[0m mychampion1.s\n");
	ft_putstr("\e[32mBonus:\e[0m\n");
	ft_putstr("	\e[36m*\e[0m can create several .cor from different .s files at once: ./asm [-hfqec] mychampion1.s mychampion2.s\n");
	ft_putstr("\e[36m-q	quit\e[0m: lists all errors from .s file instead of quitting at first error. Will prevent creation of .cor in case of errors. \n");
	ft_putstr("\e[36m-f	folder\e[0m: create a folder my_champs if it doesn't already exist or add all new .cor to this folder if it already exists.\n");
	ft_putstr("\e[36m-e	error\e[0m: tell which line has an input error.\n");
	ft_putstr("\e[36m-c	color\e[0m: add some \e[33mc\e[36mo\e[35ml\e[32mo\e[31m\e[33mr\e[0m.\n");
	exit(0); //faut pas exit proprement?
}

void	activate_flag(unsigned int *flag, char c)
{
	if (c == 'h')
		print_help();
	c == 'e' ? *flag |= BONUS_MANAGE_ERROR : 0;
	c == 'f' ? *flag |= BONUS_FOLDER : 0;
	c == 'q' ? *flag |= BONUS_DONT_QUIT : 0;
	c == 'c' ? *flag |= BONUS_COLOR : 0;
}


void	init_bonus(unsigned int *flag, char **av)
{
	char	*flags;
	int		i;
	int		j;

	*flag = 0;
	flags = "hefqc\0";
	j = 0;
	++av;
	while (av[j])
	{
		i = -1;
		while (av[j][0] == '-' && flags[++i])
			ft_strchr(av[j], flags[i]) ? activate_flag(flag, flags[i]) : 0;
		++j;
	}
}
