/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:21:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/17 19:25:46 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_instruc(t_assembler *as)
{
	t_instruc *tmp;
	tmp = as->instruc;
	while (tmp)
	{
		ft_putstr("-----------------maillon-----------------------\n");
		ft_printf("label: %s\ncommand: %s\n", tmp->label, tmp->command);
		ft_putstr("----params:-----\n");
		ft_print_tab(tmp->param);
		tmp = tmp->next;
	}
	ft_putstr("-----------------------------------------------\n");
}
