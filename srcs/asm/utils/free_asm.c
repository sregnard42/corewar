/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:26:47 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/19 16:16:05 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	free_header(t_header *header)
{
	if (!header)
		return ;
	header->name ? ft_memdel((void **)&header->name) : 0;
	header->comment ? ft_memdel((void **)&header->comment) : 0;
	ft_memdel((void **)&header);
}

void	free_same_label(t_same_label *label)
{
	t_same_label	*tmp;
	t_same_label	*current;

	if (!label)
		return ;
	current = label;
	while (current)
	{
		tmp = current;
		current = current->next;
		ft_memdel((void **)&tmp->name);
		ft_memdel((void **)&tmp);
	}
}

void	free_label(t_label *label)
{
	t_label	*tmp;

	if (!label)
		return ;
	tmp = label;
	while (label)
	{
		tmp = label;
		label = label->next;
		tmp->name ? ft_memdel((void **)&tmp->name) : 0;
		ft_memdel((void **)&tmp);
	}
}

static void	free_instruc(t_instruc *instruc)
{
	t_instruc	*tmp;
	int			i;

	if (!instruc)
		return ;
	tmp = instruc;
	while (instruc)
	{
		tmp = instruc;
		instruc = instruc->next;
		tmp->label ? free_same_label(tmp->label) : 0;
		tmp->command ? ft_memdel((void **)&tmp->command) : 0;
		i = -1;
		while (++i < 3)
			tmp->param[i] ? ft_memdel((void **)&tmp->param[i]) : 0;
		ft_memdel((void **)&tmp->param);
		tmp->param_type ? ft_memdel((void **)&tmp->param_type) : 0;
		ft_memdel((void **)&tmp);
	}
}

void		free_asm(void *assembler)
{
	t_assembler *my_asm;

	my_asm = (t_assembler *)assembler;
	if (!my_asm)
		return ;
	my_asm->header ? free_header(my_asm->header) : 0;
	my_asm->folder ? ft_memdel((void **)&my_asm->folder) : 0;
	my_asm->file_name_s ? ft_memdel((void **)&my_asm->file_name_s) : 0;
	my_asm->file_name_cor ? ft_memdel((void **)&my_asm->file_name_cor) : 0;
	my_asm->labels ? free_label(my_asm->labels) : 0;
	my_asm->param_labels ? free_label(my_asm->param_labels) : 0;
	my_asm->instruc ? free_instruc(my_asm->instruc) : 0;
}
