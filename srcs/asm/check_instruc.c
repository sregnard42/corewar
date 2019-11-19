/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:30:13 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/19 15:05:27 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int		tab_len(char **tab)
{
	int		i;
		i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

/*
** check_label_chars() must be: "abcdefghijklmnopqrstuvwxyz_0123456789"
*/

int		check_label_chars(t_assembler *as, char *str)
{
	int	i;
	int	j;
	int	len_j;
	int	len_i;

	i = 0;
	j = 0;
	ft_printf("str = %s\n", str);
	len_j = ft_strlen(LABEL_CHARS);
	len_i = ft_strlen(str);
	while (i < len_i && j < len_j && str[i] != LABEL_CHARS[j])
	{
		j++;
		if (j == 37)
		{
			ft_printf("%s --> ", str);
			ft_error(as, &free_asm, "Label with invalid characters.\n");
		}
		if (str[i] == LABEL_CHARS[j])
		{
			i++;
			j = 0;
		}
	}
	return (1);
}

/*
** is_label() checks if it's a label /!\ possible d'avoir un label invalide ? (ex trop long)
*/

int		is_label(t_assembler *as, char *part)
{
	char *ret;
	char *str;

	if ((ret = ft_strchr(part, LABEL_CHAR)) == NULL)
		return (0);
	if (!(str = ft_strsub(part, 0,  ft_strchr(part,  LABEL_CHAR) - part)))
		ft_error(as, &free_asm, "Malloc failed\n");
	if (ft_strcmp(ret, ":") == 0)
	{
		check_label_chars(as, str);
		return (1);
	}
	return (0);
}

/*
** which_command() initiates the arrays of all commands and checks them.
*/

int		which_command(t_assembler *as, char *part)
{
	int		i;

	i = 0;
	while (i < 16 && ft_strcmp(part, as->commands[i].command) != 0)
		i++;
	return (i);
}

/*
** which_param() checks the type of the params
*/

char	which_params(char *param)
{
	if (!param || !*param)
		return (0);
	if (*param == 'r')
	{
		ft_printf("%s is a registre\n", param);
		param++;
		if (ft_isnumber(param))
			return (1);
	}
	else if (*param == DIRECT_CHAR)
	{
		param++;
		ft_printf("%s is a direct\n", param);
		if (*param == LABEL_CHAR || ft_isnumber(param))
			return (2);
	}
	else
	{
		ft_printf("%s is an indirect\n", param);
		if (*param == LABEL_CHAR || ft_isnumber(param))
			return (3);
	}
	return (0);
}

/*
** check_param() checks if the param is compatible with the instruction
*/

char	check_param(t_assembler *as, int id_command, char id_param, int nb_param)
{
	int	type;

	type = as->commands[id_command].param[nb_param];
	if (type == 7 || type == id_param)
		return (1);
	else if (id_param == 1)
		return (type == 3 || type == 5 ? 1 : 0);
	else if (id_param == 2)
		return (type == 3 || type == 6 ? 1 : 0);
	else if (id_param == 3)
		return (type == 5 || type == 6 ? 1 : 0);
	return (0);
}

/*
** is_param() checks if the params are compatible with the command given
*/

int		is_param(t_assembler *as, int id_command, char *part, int nb_param)
{
	// EN COURS
	char	id_param;

	id_param = which_params(part);
	if (check_param(as, id_command, id_param, nb_param) == 1)
		ft_printf("Yes, bon parametre\n");
	else
		ft_printf("Noooooo, mauvais parametre\n");
	if (id_param != 0)
		return (1);
	return (0);
}

/*
** check_instruc() splits the line to check each part, once all is good,
** call add_instruc to save the line.
*/

void	check_instruc(t_assembler *as, char *line)
{
	char	**tab;
	int		len;
	int		i;
	int		id_command;
	int		nb_param;
	int		tmp;
	char	ocp;

	ocp = 0;
	(void)ocp;
	i = 0;
	nb_param = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, "Malloc failed\n");
	len = tab_len(tab);
	while (i < len)
	{
		if (is_label(as, tab[i]) == 1)
			ft_printf("'%s' is a		label\n", tab[i]);
		else if ((tmp = which_command(as, tab[i])) < 16)
		{
			id_command = tmp;
			ft_printf("'%s' is a		command\n", as->commands[id_command].command);
		}
		else if (is_param(as, id_command, tab[i], nb_param++) == 1)
			// ft_printf("'%s' is a			param\n", tab[i]);
			;
		else
		{
			ft_printf("%s --> SYNTAX ERROR\n", tab[i]);
			// ft_error(as, &free_asm, "syntax error, element is neither a label nor a command nor a parameter\n");
		}
		i++;
	}
	ft_printf("\n");
	add_instruct(as, line);
}
