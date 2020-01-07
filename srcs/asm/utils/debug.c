/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 17:01:50 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/07 17:04:01 by lgaultie         ###   ########.fr       */
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
		ft_putstr("----stuffs:-----\n");
		ft_printf("param_type = %s\n", tmp->param_type);
		ft_printf("direct_size = %d\n", tmp->direct_size);
		ft_printf("ocp = %c\n", tmp->ocp);
		ft_printf("size = %d\n", tmp->size);
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
