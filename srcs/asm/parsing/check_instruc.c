/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:30:13 by lgaultie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/08 14:14:34 by lgaultie         ###   ########.fr       */
=======
/*   Updated: 2020/01/08 12:24:23 by chrhuang         ###   ########.fr       */
>>>>>>> 8c9bd19b4e02a744c7739e83a05d84396946c258
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** check_label_chars() must be: "abcdefghijklmnopqrstuvwxyz_0123456789"
*/

void		check_label_chars(t_assembler *as, char *str)
{
	int	i;
	int	j;
	int	len_j;
	int	len_i;

	i = 0;
	j = 0;
	len_j = ft_strlen(LABEL_CHARS);
	len_i = ft_strlen(str);
	while (i < len_i && j < len_j && str[i] != LABEL_CHARS[j])
	{
		j++;
		if (j == len_j)
		{
			manage_error(as, &free_asm, as->epure_line, INVALID_LABEL);
		}
		if (str[i] == LABEL_CHARS[j])
		{
			i++;
			j = 0;
		}
	}
}

/*
** is_label() checks if it's a label /!\ possible d'avoir un label invalide ?
** (ex trop long)
** returns SUCCESS if it's a label, FAIL if it's not, and ERROR for comments
** to ignore.
*/

int		is_label(t_assembler *as, char *part)
{
	char	*ret;
	char	*str;
	char	*label;

	if (part[0] == COMMENT_CHAR || part[0] == ';')
		return (ERROR);
	if ((ret = ft_strchr(part, LABEL_CHAR)) == NULL \
		|| ft_strchr(part, DIRECT_CHAR) != NULL)
		return (FAIL);
	if (ft_strlen(ret) > 1)
		manage_error(as, &free_asm, as->epure_line, SPACE_LABEL);
	if (!(str = ft_strsub(part, 0, ret - part)))
		manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	if (ft_strlen(ret) == 1 && ret[0] == LABEL_CHAR)
	{
		check_label_chars(as, str);
		if (!(label = ft_strsub(str, 0, ft_strchr(part, LABEL_CHAR) - part)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
		if (ft_strlen(label) == 0)
			manage_error(as, &free_asm, as->epure_line, EMPTY_LABEL);
		save_label_to_check(as, label);
		ft_memdel((void**)&label);
		ft_memdel((void**)&str);
		return (SUCCESS);
	}
	ft_memdel((void**)&str);
	return (FAIL);
}

/*
** which_command() goes through the array of all commands to find the one given.
*/

int		which_command(t_assembler *as, char *part)
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

void	is_command(t_assembler *as, char **tmp, char *param_type)
{
	int		id_command;
	int		nb_param;

	id_command = 0;
	nb_param = 0;
	if ((id_command = which_command(as, *tmp)) < 16)
	{
		while (*(++tmp))
		{
			if (is_param(as, id_command, *tmp, nb_param++, param_type) == FAIL)
				nb_param--;
		}
		if (nb_param != as->commands[id_command].nb_params)
			manage_error(as, &free_asm, as->epure_line, WRONG_NB_PARAM);
		add_instruct(as, param_type, id_command);
	}
	else
	{
		manage_error(as, &free_asm, as->epure_line, CMD_NOT_FOUND);
	}
}

/*
** check_instruc() check if the line is a label,
** si c'est un label, skip le premier element
** et envoie le reste dans is_command
*/

void	check_instruc(t_assembler *as, char **tab, char *param_type)
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

void	epure_line(t_assembler *as)
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
		if (as->line[i] == SEPARATOR_CHAR)
			as->nb_sep++;
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

void	save_label(t_assembler *as)
{
	t_instruc	*tmp;
	t_instruc	*new;
	int			i;

	//dans le cas ou on a une ligne avec un mot
	if (!(ft_strchr(as->line, LABEL_CHAR)))
		manage_error(as, &free_asm, as->epure_line, JUNK);
	//dans le cas ou on a une ligne avec un mot qui est un label
	i = 0;
	while (as->line[i])
	{
		if (as->line[i] == LABEL_CHAR)
			as->line[i] = '\0';
		i++;
	}
	//le : en fin est écrasé
	// creation du maillon contenant cette ligne (juste un label)
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
	//il faut creer la liste chainée same_label et copier as->line dans son dernier maillon
	save_same_label(as, new, as->line);
	// if (!(new->label = ft_strdup(as->line)))
	// 	manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	//copier le label dans la liste chainée des labels
	save_label_to_check(as, as->line);
	//dire qu'on a eu un passage a la ligne
	as->newline = 1;
	print_instruc(as);
	// print_labels(as);
	return ;
}

/*
** parse_instruction() checks if header is complete. Then cut the instruction
** to send each parts in check_instruc.
*/

void	parse_instruction(t_assembler *as)
{
	char	**tab;
	char	*param_type;

	as->nb_sep = 0;
	epure_line(as);
	as->line = ft_strclean(as->line); // On doit free le as->line vu que j'ecrase le malloc
	ft_printf("my_line = %s\n", as->line);
	if (as->line[0] == '\0' || as->line[0] == COMMENT_CHAR || as->line[0] == ';')
		return ;
	if (!as->header->name)
		manage_error(as, &free_asm, as->epure_line, EMPTY_NAME);
	if (!as->header->comment)
		manage_error(as, &free_asm, as->epure_line, EMPTY_COMMENT);
	if (ft_strchr(as->line, ' '))
	{
		if (!(tab = ft_strsplit(as->line, ' ')))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
	else // Si on as label: saut a la ligne
	{
		save_label(as);
		return ;
	}
	if (!(param_type = ft_memalloc(sizeof(char) * 3)))
		manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	check_instruc(as, tab, param_type);
}
