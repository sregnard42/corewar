/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:21:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/06 17:04:03 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_usage()
{
	ft_putstr("\e[32mUsage:\e[0m	./asm \e[35m[-hfqec]\e[0m mychampion1.s\n");
	ft_putstr("\e[35mHelp\e[0m on program and bonus: ./asm \e[35m-h\e[0m\n");
}

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

void	print_advices(t_assembler *as)
{
	if (as->bonus & BONUS_COLOR)
		ft_putstr("\e[1;32m");
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
