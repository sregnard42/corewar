/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:28:10 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 18:49:13 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** which_command() goes through the array of all commands to find the one given.
*/

int			which_command(t_assembler *as, char *part)
{
	int		i;

	i = 0;
	while (part && i < 16 && ft_strcmp(part, as->commands[i].command) != 0)
		i++;
	return (i);
}

/*
** Regarde si le premier element de tmp est une commande, si oui, on verifie que
** les prochains element de tmp sont bien des parametres
** Ensuite, ajoute l'instruction dans la structure as
** si is_param fail c'est quil y a deux commandes a la suite, donc on diminue
** le nombre de parametres
*/

static void	is_command(t_assembler *as, char **tmp, char *param_type)
{
	int		nb_param;

	as->id_command = 0;
	nb_param = 0;
	if ((as->id_command = which_command(as, *tmp)) < 16)
	{
		while (*(++tmp))
		{
			if (is_param(as, *tmp, nb_param++, param_type) == FAIL)
				nb_param--;
		}
		if (nb_param != as->commands[as->id_command].nb_params)
			manage_error(as, &free_asm, WRONG_NB_PARAM);
		add_instruct(as, param_type, as->id_command);
	}
	else
	{
		manage_error(as, &free_asm, CMD_NOT_FOUND);
	}
}

/*
** check_instruc() check if the line is a label,
** si c'est un label, skip le premier element
** et envoie le reste dans is_command
*/

static void	check_instruc(t_assembler *as, char **tab, char *param_type)
{
	char	**tmp;

	tmp = tab;
	if (is_label(as, *tmp) == SUCCESS)
		is_command(as, ++tmp, param_type);
	else
		is_command(as, tmp, param_type);
	ft_free_tab(&tab);
}

/*
** epure_line() change all tabulation or ',' by space and all '#' by \0
*/

static void	epure_line(t_assembler *as)
{
	int		i;

	i = -1;
	while (as->line[++i])
	{
		if (as->line[i] == COMMENT_CHAR || as->line[i] == ';')
		{
			as->line[i] = '\0';
			i = -1;
			while (as->line[++i])
				if (as->line[i] != ' ')
					return ;
			as->line[0] = '\0';
			return ;
		}
		as->line[i] == SEPARATOR_CHAR ? as->nb_sep++ : 0;
		if (as->line[i] == '\t' || as->line[i] == SEPARATOR_CHAR)
			as->line[i] = ' ';
	}
	i = -1;
	while (as->line[++i])
		if (as->line[i] != ' ')
			return ;
	as->line[0] = '\0';
	return ;
}

/*
** analyse_instruction() checks if header is complete. Then cut the instruction
** to send each parts in check_instruc.
*/

void		analyse_instruction(t_assembler *as)
{
	char	**tab;
	char	*tmp;
	char	*param_type;

	as->nb_sep = 0;
	epure_line(as);
	tmp = as->line;
	as->line = ft_strclean(as->line);
	ft_memdel((void **)&tmp);
	if (*as->line == '\0' || *as->line == COMMENT_CHAR || *as->line == ';')
		return ;
	!as->header->name ? manage_error(as, &free_asm, EMPTY_NAME) : 0;
	!as->header->comment ? manage_error(as, &free_asm, EMPTY_COMMENT) : 0;
	if (ft_strchr(as->line, ' '))
	{
		if (!(tab = ft_strsplit(as->line, ' ')))
			manage_error(as, &free_asm, ERROR_MALLOC);
	}
	else
		return (save_label(as));
	if (!(param_type = ft_memalloc(sizeof(char) * 3)))
		manage_error(as, &free_asm, ERROR_MALLOC);
	check_instruc(as, tab, param_type);
}
