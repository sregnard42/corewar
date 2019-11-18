/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:30:13 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/18 17:56:10 by lgaultie         ###   ########.fr       */
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
	as->commands[0] = "live";
	as->commands[1] = "ld";
	as->commands[2] = "st";
	as->commands[3] = "add";
	as->commands[4] = "sub";
	as->commands[5] = "and";
	as->commands[6] = "or";
	as->commands[7] = "xor";
	as->commands[8] = "zjmp";
	as->commands[9] = "ldi";
	as->commands[10] = "sti";
	as->commands[11] = "fork";
	as->commands[12] = "lld";
	as->commands[13] = "lldi";
	as->commands[14] = "lfork";
	as->commands[15] = "add";
	while (i < 16 && ft_strcmp(part, as->commands[i]) != 0)
		i++;
	return (i);
}

/*
** is_param() checks if the params are compatible with the command given
*/

int		is_param(int id_command, char *part)
{
	// EN COURS
	(void)part;
	(void)id_command;
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

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, "Malloc failed\n");
	len = tab_len(tab);
	while (i < len)
	{
		if (is_label(as, tab[i]) == 1)
			ft_printf("'%s' is a		label\n", tab[i]);
		else if ((id_command = which_command(as, tab[i])) < 16)
			ft_printf("'%s' is a		command\n", as->commands[id_command]);
		else if (is_param(id_command, tab[i]) == 1)
			ft_printf("'%s' is a			param\n", tab[i]);
		else
		{
			ft_printf("%s --> ", tab[i]);
			ft_printf("SYNTAX ERROR\n");
			// ft_error(as, &free_asm, "syntax error, element is neither a label nor a command nor a parameter\n");
		}
		i++;
	}
	add_instruct(as, line);
}
