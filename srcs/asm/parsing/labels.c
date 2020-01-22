/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:41:40 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/22 12:36:09 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	save_same_label() create or add to end of list of one node's label. As
** several labels can points to the same instruction line, we stock this
** instruction in our node with a list of all labels pointing to it.
*/

void		save_same_label(t_assembler *as, t_instruc *new, char *name)
{
	t_same_label	*label;
	t_same_label	*tmp;

	if (check_if_exists_instruc(as, name) == SUCCESS)
		return ;
	if (!new->label)
	{
		if (!(new->label = ft_memalloc(sizeof(t_same_label))))
			manage_error(as, &free_asm, ERROR_MALLOC);
		if (!(new->label->name = ft_strdup(name)))
			manage_error(as, &free_asm, ERROR_MALLOC);
	}
	else
	{
		if (!(label = ft_memalloc(sizeof(t_same_label))))
			manage_error(as, &free_asm, ERROR_MALLOC);
		if (!(label->name = ft_strdup(name)))
			manage_error(as, &free_asm, ERROR_MALLOC);
		tmp = new->label;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = label;
	}
}

/*
** check_if_exists() depends on mode, returns SUCCESS if param is already
** defined or FAIL it doesn't exist
*/

static int	check_if_exists(t_assembler *as, char *param, int mode)
{
	t_label	*tmp;

	if (mode == 1)
		tmp = as->labels;
	if (mode == 2)
		tmp = as->param_labels;
	while (tmp)
	{
		if (ft_strcmp(param, tmp->name) == 0)
			return (SUCCESS);
		tmp = tmp->next;
	}
	return (FAIL);
}

/*
** save_label_to_check() create a list of existing label, to check later if
** we are trying to create an already existing label
*/

void		save_label_to_check(t_assembler *as, char *label)
{
	t_label	*tmp;
	t_label	*new;

	if (check_if_exists(as, label, 1) == SUCCESS)
		return ;
	tmp = as->labels;
	if (!(new = ft_memalloc(sizeof(t_label))))
		manage_error(as, &free_asm, ERROR_MALLOC);
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		as->labels = new;
	if (!(new->name = ft_strdup(label)))
		manage_error(as, &free_asm, ERROR_MALLOC);
}

/*
** save_label_param() create a list of label parameter, to check later if
** the label associated truly exists
*/

void		save_label_param(t_assembler *as, char *param)
{
	t_label	*tmp;
	t_label	*new;

	if (check_if_exists(as, param, 2) == SUCCESS)
		return ;
	tmp = as->param_labels;
	if (!(new = ft_memalloc(sizeof(t_label))))
		manage_error(as, &free_asm, ERROR_MALLOC);
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		as->param_labels = new;
	if (!(new->name = ft_strdup(param)))
		manage_error(as, &free_asm, ERROR_MALLOC);
}

/*
** check_existing_labels() checks both lists of label and parameter containing
** a label, to check if the label parameter refers to an existing label
*/

void		check_existing_labels(t_assembler *as)
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
				break ;
			}
			if (tmp_label->next == NULL)
				manage_error(as, &free_asm, NO_EXIST_LABEL);
			tmp_label = tmp_label->next;
		}
		tmp_params = tmp_params->next;
	}
}
