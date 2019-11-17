/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:56:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/17 19:20:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

void	init_room(t_instruc *new, char *line)
{
	char	**tab;
	int		len;
	int		label;

	label = 0;
	tab = ft_strsplit(line, ' ');
	len = tab_len(tab);
	if (ft_strchr(tab[0], LABEL_CHAR) != NULL)
	{
		new->label = ft_strdup(tab[0]);
		label = 1;
	}
	if (len == 5) //label + fonction a 3 params
	{
		new->command = ft_strdup(tab[1]);
		new->param[0] = ft_strdup(tab[2]);
		new->param[1] = ft_strdup(tab[3]);
		new->param[2] = ft_strdup(tab[4]);
	}
	if (label == 0 && len == 4)  //no label + fonction a 3 params
	{
		new->command = ft_strdup(tab[0]);
		new->param[0] = ft_strdup(tab[1]);
		new->param[1] = ft_strdup(tab[2]);
		new->param[2] = ft_strdup(tab[3]);
	}
	if (label == 1 && len == 4)  //label + fonction a 2 params
	{
		new->command = ft_strdup(tab[1]);
		new->param[0] = ft_strdup(tab[2]);
		new->param[1] = ft_strdup(tab[3]);
		new->param[2] = ft_strdup("");
	}
	if (label == 0 && len == 3)  //no label + fonction a 2 params
	{
		new->command = ft_strdup(tab[0]);
		new->param[0] = ft_strdup(tab[1]);
		new->param[1] = ft_strdup(tab[2]);
		new->param[2] = ft_strdup("");
	}
	if (label == 0 && len == 2)  //no label + fonction a 1 params
	{
		new->command = ft_strdup(tab[0]);
		new->param[0] = ft_strdup(tab[1]);
		new->param[1] = ft_strdup("");
		new->param[2] = ft_strdup("");
	}
	if (label == 1 && len == 3)  //label + fonction a 1 params
	{
		new->command = ft_strdup(tab[1]);
		new->param[0] = ft_strdup(tab[2]);
		new->param[1] = ft_strdup("");
		new->param[2] = ft_strdup("");
	}
	ft_free_tab(&tab);
}

void	add_instruct(t_assembler *as, char *line)
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
	init_room(new, line);
}

void	parse_instruction(t_assembler *as, char *line)
{
	if (line[0] == '\0' || ft_strchr(line, COMMENT_CHAR) != NULL)
		return ;
	// ft_printf("line = |%s|\n",line);
	// if (!(tab = ft_strsplit(line, ' ')))
	// 	return ;
	// if (ft_strchr(tab[0], LABEL_CHAR) != NULL)
	// 	ft_printf("%s is a label\n", tab[0]);
	// ft_print_tab(tab);
	// ft_putendl("----------------");
	add_instruct(as, line);
}
