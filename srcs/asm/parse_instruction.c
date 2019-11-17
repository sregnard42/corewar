/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:56:09 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/17 22:02:22 by chrhuang         ###   ########.fr       */
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
	// int		len;
	// int		label;
	int		i;
	int		j;

	// label = 0;
	i = 0;
	j = 0;
	tab = ft_strsplit(line, ' ');
	// len = tab_len(tab);
	if (ft_strchr(tab[i], LABEL_CHAR) != NULL)
	{
		tab[i][ft_strlen(tab[i]) - 1] = '\0';
		new->label = ft_strdup(tab[i]);
		// label = 1;
		i++;
	}
	new->command = ft_strdup(tab[i++]);
	while (j < 3)
		if (tab[i])
			new->param[j++] = ft_strdup(tab[i++]);
		else
			break ;
	// if (len == 5) //label + fonction a 3 params
	// {
	// 	new->command = ft_strdup(tab[1]);
	// 	new->param[0] = ft_strdup(tab[2]);
	// 	new->param[1] = ft_strdup(tab[3]);
	// 	new->param[2] = ft_strdup(tab[4]);
	// }
	// if (label == 0 && len == 4)  //no label + fonction a 3 params
	// {
	// 	new->command = ft_strdup(tab[0]);
	// 	new->param[0] = ft_strdup(tab[1]);
	// 	new->param[1] = ft_strdup(tab[2]);
	// 	new->param[2] = ft_strdup(tab[3]);
	// }
	// if (label == 1 && len == 4)  //label + fonction a 2 params
	// {
	// 	new->command = ft_strdup(tab[1]);
	// 	new->param[0] = ft_strdup(tab[2]);
	// 	new->param[1] = ft_strdup(tab[3]);
	// 	new->param[2] = ft_strdup("");
	// }
	// if (label == 0 && len == 3)  //no label + fonction a 2 params
	// {
	// 	new->command = ft_strdup(tab[0]);
	// 	new->param[0] = ft_strdup(tab[1]);
	// 	new->param[1] = ft_strdup(tab[2]);
	// 	new->param[2] = ft_strdup("");
	// }
	// if (label == 0 && len == 2)  //no label + fonction a 1 params
	// {
	// 	new->command = ft_strdup(tab[0]);
	// 	new->param[0] = ft_strdup(tab[1]);
	// 	new->param[1] = ft_strdup("");
	// 	new->param[2] = ft_strdup("");
	// }
	// if (label == 1 && len == 3)  //label + fonction a 1 params
	// {
	// 	new->command = ft_strdup(tab[1]);
	// 	new->param[0] = ft_strdup(tab[2]);
	// 	new->param[1] = ft_strdup("");
	// 	new->param[2] = ft_strdup("");
	// }
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
	add_instruct(as, line);
}
