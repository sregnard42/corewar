/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:21:09 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 17:14:39 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_usage(void)
{
	ft_putstr("\e[32mUsage:\e[0m	./asm \e[35m[-hfec]\e[0m mychampion1.s\n");
	ft_putstr("\e[35mHelp\e[0m on program and bonus: ./asm \e[35m-h\e[0m\n");
}

void	print_help(void)
{
	ft_putstr("\e[32m");
	ft_putstr("Usage:\n\t\e[0m ./asm \e[36m[-hfec]\e[0m mychampion1.s\n");
	ft_putstr("\e[32mBonuses:\e[0m\n");
	ft_putstr("	\e[36m*\e[0m can create several .cor from different .s files ");
	ft_putstr("at once:\n\t\t\e[36m./asm [-hfec] champion1.s champion2.s\n");
	ft_putstr("	*\e[0m use \e[36m./asm_checker.sh champion1.s ");
	ft_putstr("champion2.s\e[0m A script to see differences with ");
	ft_putstr("the asm given in ressources.\n");
	ft_putstr("\e[32mBonuses flags:\e[0m\n");
	ft_putstr("\e[36m-f	folder\e[0m: create a folder");
	ft_putstr(" my_champs if it doesn't already exist or add all new .cor ");
	ft_putstr("to this folder if it already exists.\n");
	ft_putstr("\e[36m-e	error\e[0m: tell which line has an input error.\n");
	ft_putstr("\e[36m-c	color\e[0m: add some ");
	ft_putstr("\e[33mc\e[36mo\e[35ml\e[32mo\e[31m\e[33mr\e[0m.\n");
	exit(0);
}

void	print_advices(t_assembler *as)
{
	if (as->bonus & BONUS_COLOR)
		ft_putstr("\e[32m");
	ft_putstr("\nREMINDERS:\n");
	if (as->bonus & BONUS_COLOR)
	{
		ft_putstr("\e[0m");
		ft_putstr("\e[32m");
	}
	ft_putstr("\t* Header:\e[0m\n");
	ft_putstr("\t.name \"champion's name\"\n");
	ft_putstr("\t.comment \"some comment\"\n");
	if (as->bonus & BONUS_COLOR)
		ft_putstr("\e[32m");
	ft_putstr("\t* One instruction per line:\e[0m\n");
	ft_putstr("\t<label> <command> <argument1> , <argument2> , ..\n");
}

void	print_file_name(t_assembler *as)
{
	as->bonus & BONUS_COLOR ? ft_putstr("\e[35m") : 0;
	ft_printf("\n------------ \e[0m%s ", as->file_name_s);
	as->bonus & BONUS_COLOR ? ft_putstr("\e[35m") : 0;
	ft_putstr("-------------\e[0m\n\n");
}
