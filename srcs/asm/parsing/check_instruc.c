/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:30:13 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/26 14:01:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

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
		if (j == 37)
		{
			ft_printf("%s --> ", str);
			ft_error(as, &free_asm, INVALID_LABEL);
		}
		if (str[i] == LABEL_CHARS[j])
		{
			i++;
			j = 0;
		}
	}
}

/*
** is_label() checks if it's a label /!\ possible d'avoir un label invalide ? (ex trop long)
** returns 1 if it's a label, 0 if it's not, and -1 for comments to ignore
*/

int		is_label(t_assembler *as, char *part)
{
	char *ret;
	char *str;
	char *label;

	ft_printf("(is_label)part = %s\n", part);
	if (part[0] == '#')
		return (-1);
	if ((ret = ft_strchr(part, LABEL_CHAR)) == NULL \
		|| ft_strchr(part, DIRECT_CHAR) != NULL)
		return (0);
	if (ft_strlen(ret) > 1)
		ft_error(as, &free_asm, SPACE_LABEL);
	if (!(str = ft_strsub(part, 0,  ret - part)))
		ft_error(as, &free_asm, ERROR_MALLOC);
	if (ft_strcmp(ret, ":") == 0)
	{
		check_label_chars(as, str);
		if (!(label = ft_strsub(str, 0, ft_strchr(part, ':') - part)))
			ft_error(as, &free_asm, ERROR_MALLOC);
		if (ft_strlen(label) == 0)
			ft_error(as, &free_asm, EMPTY_LABEL);
		save_label_to_check(as, label);
		ft_memdel((void**)&label);
		ft_memdel((void**)&str);
		return (1);
	}
	ft_memdel((void**)&str);
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
** check_instruc() splits the line to check each part, once all is good,
** call add_instruc to save the line.
*/

void	check_instruc(t_assembler *as, char *line, int len, char **tab)
{
	int		i;
	int		ret;
	int		id_command;
	int		nb_param;
	int		tmp;
	char	param_type[3];

	i = -1;
	nb_param = 0;
	while (++i < len)
	{
		if ((ret = (is_label(as, tab[i]))) == 1)
			ft_printf("'%s' is a label\n", tab[i]);
		else if (ret == -1) //on a #ahah en fin de ligne
			break;
		else if ((tmp = which_command(as, tab[i])) < 16)
		{
			id_command = tmp;
			ft_printf("'%s' is a command\n", as->commands[id_command].command);
		}
		else if (is_param(as, id_command, tab[i], nb_param++, param_type) == 1)
			;
		else
			ft_error(as, &free_asm, WTF_IS_THIS);
	}
	ft_free_tab(&tab);
	add_instruct(as, line, param_type, id_command);
	///////////////
	ft_printf("param_type[0] = %c | param_type[1] = %c | param_type[2] = %c\n", param_type[0] + '0', param_type[1] + '0', param_type[2] + '0');
}

void	parse_instruction(t_assembler *as, char *line)
{
	char	**tab;
	int		len;

	if (line[0] == '\0' || line[0] == '#')
		return ;
	if (!as->header->name)
		ft_error(as, &free_asm, EMPTY_NAME);
	if (!as->header->comment)
		ft_error(as, &free_asm, EMPTY_COMMENT);
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, ERROR_MALLOC);
	len = ft_nb_str_tab(tab);
	ft_putstr("tab -----------------------------------------\n");
	ft_print_tab(tab);
	ft_putstr("---------------------------------------------\n");
	check_instruc(as, line, len, tab);
}
