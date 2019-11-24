/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:30:13 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/24 15:23:59 by chrhuang         ###   ########.fr       */
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
			ft_error(as, &free_asm, "Label with invalid characters.\n");
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
*/

int		is_label(t_assembler *as, char *part)
{
	char *ret;
	char *str;
	char *label;

	ft_printf("part = %s\n", part);
	if ((ret = ft_strchr(part, LABEL_CHAR)) == NULL)
		return (0);
	if (!(str = ft_strsub(part, 0,  ret - part)))
		ft_error(as, &free_asm, "Malloc failed\n");
	if (ft_strcmp(ret, ":") == 0)
	{
		check_label_chars(as, str);
		if (!(label = ft_strsub(str, 0, ft_strchr(part, ':') - part)))
			ft_error(as, &free_asm, "Malloc failed\n");
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

void	check_instruc(t_assembler *as, char *line)
{
	char	**tab;
	int		len;
	int		i;
	int		id_command;
	int		nb_param;
	int		tmp;
	char	*param_type;

	i = -1;
	nb_param = 0;
	if (!as->header->name || !as->header->comment)
		ft_error(as, &free_asm, "Invalid name or comment at top of file.\n");
	if ((param_type = ft_memalloc(sizeof(char) * 3)) == NULL)
		ft_error(as, &free_asm, "Malloc failed\n");
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, "Malloc failed\n");
	len = ft_nb_str_tab(tab);
	while (++i < len)
	{
		if (is_label(as, tab[i]) == 1)
			ft_printf("'%s' is a label\n", tab[i]);
		else if ((tmp = which_command(as, tab[i])) < 16)
		{
			id_command = tmp;
			ft_printf("'%s' is a command\n", as->commands[id_command].command);
		}
		else if (is_param(as, id_command, tab[i], nb_param++, param_type) == 1)
			;
		else
			ft_error(as, &free_asm, "syntax error, element is neither a label nor a command nor a parameter\n");
	}
	ft_free_tab(&tab);
	add_instruct(as, line, param_type, id_command);
	///////////////
	ft_printf("param_type[0] = %c | param_type[1] = %c | param_type[2] = %c\n", param_type[0] + '0', param_type[1] + '0', param_type[2] + '0');
}

void	parse_instruction(t_assembler *as, char *line)
{
	if (line[0] == '\0' || ft_strchr(line, COMMENT_CHAR) != NULL)
		return ;
	check_instruc(as, line);
}
