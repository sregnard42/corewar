/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:40:46 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/21 17:40:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_room(t_assembler *as, t_instruc *new, char *line)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, "Malloc failed\n");
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

void	add_instruct(t_assembler *as, char *line, char *ocp)
{
	t_instruc	*tmp;
	t_instruc	*new;

	tmp = as->instruc;
	if (!(new = ft_memalloc(sizeof(t_instruc))))
		ft_error(as, &free_asm, "Malloc failed\n");
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
	new->ocp = ocp;
	init_room(as, new, line);
}

void	parse_instruction(t_assembler *as, char *line)
{
	if (line[0] == '\0' || ft_strchr(line, COMMENT_CHAR) != NULL)
		return ;
	check_instruc(as, line);
}
