/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:21:00 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/07 14:02:06 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	activate_flag(unsigned int *flag, char c)
{
	if (c == 'h')
		print_help();
	c == 'e' ? *flag |= BONUS_MANAGE_ERROR : 0;
	c == 'f' ? *flag |= BONUS_FOLDER : 0;
	c == 'c' ? *flag |= BONUS_COLOR : 0;
}

void	init_bonus(unsigned int *flag, char **av)
{
	char	*flags;
	int		i;
	int		j;

	*flag = 0;
	flags = "hefc\0";
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
