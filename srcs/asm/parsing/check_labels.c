/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:12:23 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/21 16:54:35 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_if_exists(t_assembler *as, char *param, int mode)
{
	t_label	*tmp;

	if (mode == 1)
		tmp = as->labels;
	if (mode == 2)
		tmp = as->param_labels;
	while (tmp)
	{
		if (ft_strcmp(param, tmp->name) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	save_label_to_check(t_assembler *as, char *label)
{
	t_label	*tmp;
	t_label	*new;

	if (check_if_exists(as, label, 1) == 0)
		return ;
	tmp = as->labels;
	if (!(new = ft_memalloc(sizeof(t_label))))
		ft_error(as, &free_asm, "Malloc failed\n");
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		as->labels = new;
	if (!(new->name = ft_strdup(label)))
		ft_error(as, &free_asm, "Malloc failed\n");
}

void	save_label_param(t_assembler *as, char *param)
{
	t_label	*tmp;
	t_label	*new;

	if (check_if_exists(as, param, 2) == 0)
		return ;
	tmp = as->param_labels;
	if (!(new = ft_memalloc(sizeof(t_label))))
		ft_error(as, &free_asm, "Malloc failed\n");
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		as->param_labels = new;
	if (!(new->name = ft_strdup(param)))
		ft_error(as, &free_asm, "Malloc failed\n");
}

int		check_existing_labels(t_assembler *as)
{
	t_label	*tmp_label;
	t_label	*tmp_params;

	tmp_label = as->labels;
	tmp_params = as->param_labels;
	while (tmp_params)
	{
		while (tmp_label)
		{
			if (ft_strcmp(tmp_label->name, tmp_params->name) == 0)
			{
				tmp_label = as->labels;
				break;
			}
			if (tmp_label->next == NULL)
				return (-1);
			tmp_label = tmp_label->next;
		}
		tmp_params = tmp_params->next;
	}
	return (0);
}
