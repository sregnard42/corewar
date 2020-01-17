/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:28:28 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/17 16:56:25 by lgaultie         ###   ########.fr       */
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

	if (!new->label)
	{
		if (!(new->label = ft_memalloc(sizeof(t_same_label))))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		if (!(new->label->name = ft_strdup(name)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
	else
	{
		if (!(label = ft_memalloc(sizeof(t_same_label))))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		if (!(label->name = ft_strdup(name)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		tmp = new->label;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = label;
	}
}

void		save_params(t_assembler *as, char **tab, int i, t_instruc *new)
{
	int		j;

	j = 0;
	while (j < 3)
	{
		if (tab[i])
		{
			if (!(new->param[j++] = ft_strdup(tab[i++])))
			{
				ft_free_tab(&tab);
				manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
			}
		}
		else
			break ;
	}
}

/*
** init_instruct() calls save_same_label() to save all labels pointing to this
** instruction. Then save in the node the command and its parameters.
*/

void		init_instruc(t_assembler *as, t_instruc *new, int id_command)
{
	char	**tab;
	int		i;

	i = 0;
	new->opcode = id_command + 1;
	if (!(tab = ft_strsplit(as->line, ' ')))
		manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	if (ft_strchr(tab[0], LABEL_CHAR) != NULL)
	{
		tab[0][ft_strlen(tab[0]) - 1] = '\0';
		save_same_label(as, new, tab[0]);
		i++;
	}
	if (!(new->command = ft_strdup(tab[i])))
	{
		ft_free_tab(&tab);
		manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
	i++;
	save_params(as, tab, i, new);
	ft_free_tab(&tab);
}

/*
** init_new() add one to size for opcode when ocp doesn't exist, add 2 for
** opcode et ocp. Calculates the total nb of bytes of the instruction
*/

void		init_new(t_assembler *as, t_instruc *new, char *param_type,
			int id_command)
{
	int		ret;

	new->param_type = param_type;
	init_instruc(as, new, id_command);
	get_ocp(new);
	ret = get_params_bytes(new);
	ret += new->ocp == 0 ? 1 : 2;
	new->size = ret;
	as->newline = 0;
}

/*
** add_instruct() add one line of instruction to our list of instruction
*/

void		add_instruct(t_assembler *as, char *param_type,
		int id_command)
{
	t_instruc	*tmp;
	t_instruc	*new;

	if (as->newline != 1)
	{
		tmp = as->instruc;
		if (!(new = ft_memalloc(sizeof(t_instruc))))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			as->instruc = new;
	}
	else
	{
		tmp = as->instruc;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = tmp;
	}
	init_new(as, new, param_type, id_command);
}
