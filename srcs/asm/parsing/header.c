/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:37:26 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 18:19:04 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		save_name_comment(t_assembler *as, int choice, char *str,
			char **dst)
{
	if (choice == SAVE_NAME)
	{
		if (ft_strlen(str) > PROG_NAME_LENGTH)
			manage_error(as, &free_asm, NAME_TOO_LONG);
	}
	if (choice == SAVE_COMMENT)
	{
		if (ft_strlen(str) > COMMENT_LENGTH)
			manage_error(as, &free_asm, COMM_TOO_LONG);
	}
	*dst = str;
}

/*
** check_quotes() parse only the name or comment (without ""), checks if they
** are too long or checks if invalid input after the name or comment
** (ex: .name "yes"no), etc...
*/

static void		check_quotes(t_assembler *as, char **dst, int choice, int error)
{
	char	*str;

	if (dst && *dst)
		manage_error(as, &free_asm, NAME_COMMENT_EXIST);
	if (!ft_strchr(as->line, '"'))
		manage_error(as, &free_asm, NO_QUOTES);
	str = ft_strchr(as->line, '"') + 1;
	if (ft_strchr(str, '"') == NULL)
		manage_error(as, &free_asm, QUOTES_NOT_CLOSED);
	if (!(ft_strchr(str, '"')))
		error = 1;
	if (error == 0 && (ft_strcmp("", ft_strchr(str, '"') + 1) != 0))
		manage_error(as, &free_asm, STUFF_AFTER);
	if (error == 0)
	{
		if (!(str = ft_strsub(str, 0, ft_strchr(str, '"') - str)))
			manage_error(as, &free_asm, ERROR_MALLOC);
	}
	else
	{
		if (!(str = ft_strdup("")))
			manage_error(as, &free_asm, ERROR_MALLOC);
	}
	save_name_comment(as, choice, str, dst);
}

/*
** epure name or comment line
*/

void			between_name_quote(t_assembler *as)
{
	char	*str;
	int		i;
	int		mode;
	int		length;

	str = as->line;
	i = 0;
	mode = 0;
	str = ft_strchr(str, '.');
	length = ft_strlen(NAME_CMD_STRING);
	if (str && ft_strncmp(NAME_CMD_STRING, str, length) == 0)
		mode = 1;
	length = ft_strlen(COMMENT_CMD_STRING);
	if (str && ft_strncmp(COMMENT_CMD_STRING, str, length) == 0)
		mode = 2;
	if (mode != 1 && mode != 2)
	{
		if (ft_strcmp(as->line, "") == 0)
			return ;
		manage_error(as, &free_asm, BAD_FORMAT);
	}
	i = ft_strlen(mode == 1 ? NAME_CMD_STRING : COMMENT_CMD_STRING);
	replace_by_spaces(as, str, i);
}

static int		compare_name_comment(t_assembler *as, char *part)
{
	int		error;

	error = 0;
	if (ft_strcmp(NAME_CMD_STRING, part) == 0)
	{
		ft_memdel((void**)&part);
		check_quotes(as, &as->header->name, SAVE_NAME, error);
		return (SUCCESS);
	}
	else if (ft_strcmp(COMMENT_CMD_STRING, part) == 0)
	{
		ft_memdel((void**)&part);
		check_quotes(as, &as->header->comment, SAVE_COMMENT, error);
		return (SUCCESS);
	}
	ft_memdel((void**)&part);
	return (FAIL);
}

/*
** check_header() if there is no space in the header line, quit.
** if finds .name or .comment, parse string between quotes in our list.
*/

int				check_header(t_assembler *as)
{
	char	*len;
	char	*part;
	char	*str;
	char	*tmp;

	if (as->header->name && as->header->comment)
		return (FAIL);
	change_sharp(as);
	tmp = as->line;
	as->line = delete_space_after(as, tmp);
	ft_memdel((void **)&tmp);
	between_name_quote(as);
	str = as->line;
	if (str)
		str = ft_strchr(str, '.');
	check_before_dot(as, str);
	if (str == NULL || (len = ft_strchr(str, '"')) == NULL)
		return (FAIL);
	if (!(tmp = ft_strsub(str, 0, len - str)))
		manage_error(as, &free_asm, ERROR_MALLOC);
	part = delete_space_after(as, tmp);
	ft_memdel((void **)&tmp);
	return (compare_name_comment(as, part));
}
