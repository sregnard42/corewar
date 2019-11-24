/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:21:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/24 14:50:26 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_instruc(t_assembler *as)
{
	t_instruc *tmp;
	tmp = as->instruc;
	ft_putstr("-----------------------------------------------\n");
	ft_putstr("      called print_instruc dans print.c\n");
	while (tmp)
	{
		ft_putstr("-----------------maillon-----------------------\n");
		ft_printf("label: %s\ncommand: %s (opcode: %d)\n", tmp->label, tmp->command, tmp->opcode);
		ft_putstr("----params:-----\n");
		ft_print_tab(tmp->param);
		tmp = tmp->next;
	}
	ft_putstr("-----------------------------------------------\n");
}

void	print_labels(t_assembler *as)
{
	t_label *tmp;
	tmp = as->labels;
	ft_putstr("-----------------------------------------------\n");
	ft_putstr("      called print_labels dans print.c\n");
	while (tmp)
	{
		ft_putstr("----------------label-----------------------\n");
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	ft_putstr("-----------------------------------------------\n");
}

void	print_param_labels(t_assembler *as)
{
	t_label *tmp;
	tmp = as->param_labels;
	ft_putstr("-----------------------------------------------\n");
	ft_putstr("      called print_param_labels dans print.c\n");
	while (tmp)
	{
		ft_putstr("----------------label-----------------------\n");
		ft_printf("%s\n", tmp->name);
		tmp = tmp->next;
	}
	ft_putstr("-----------------------------------------------\n");
}
