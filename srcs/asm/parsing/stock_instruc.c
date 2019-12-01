/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:40:46 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/01 12:27:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_room(t_assembler *as, t_instruc *new, char *line, int id_command)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new->opcode = id_command + 1;
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, ERROR_MALLOC);
	if (ft_strchr(tab[0], LABEL_CHAR) != NULL)
	{
		tab[0][ft_strlen(tab[0]) - 1] = '\0';
		new->label = ft_strdup(tab[0]);
		i++;
	}
	new->command = ft_strdup(tab[i]);
	i++;
	while (j < 3)
	{
		if (tab[i])
			new->param[j++] = ft_strdup(tab[i++]);
		else
			break ;
	}
	ft_free_tab(&tab);
}

/*
** get_size_instruction() add one for opcode when ocp doesn't exist, add 2 for
** opcode et ocp
*/

void		get_size_instruction(t_instruc *new)
{
	int		ret;

	ret = get_params_bytes(new);
	ret += new->ocp == 0 ? 1 : 2;
	new->size = ret;
	ft_printf("new->size = %d\n", new->size);
}


void	add_instruct(t_assembler *as, char *line, char *param_type, int id_command)
{
	t_instruc	*tmp;
	t_instruc	*new;

	tmp = as->instruc;
	if (!(new = ft_memalloc(sizeof(t_instruc))))
		ft_error(as, &free_asm, ERROR_MALLOC);
	if (tmp != NULL)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		tmp->prev = tmp;
	}
	else
	{
		new->prev = NULL;
		as->instruc = new;
	}
	new->param_type = param_type;
	init_room(as, new, line, id_command);
	get_ocp(new);
	get_size_instruction(new);
	ft_printf("new->size = %d\n", new->size);
}
