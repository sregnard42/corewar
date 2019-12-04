/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:37:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/04 14:05:28 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	clean_line(char *line)
{
	char	replace[3];

	replace[0] = '\t';
	replace[1] = SEPARATOR_CHAR;
	replace[2] = '\0';
	line = ft_strreplace(line, replace, ' ');
}

/*
** parse_header() parse only the name or comment (without ""), checks if they
** are too long or checks if invalid input after the name or comment
** (ex: .name "yes"no)
*/

void	parse_header(t_assembler *as, char **dst, int choice)
{
	char *str;

	if (dst && *dst)
		manage_error(as, &free_asm, as->line, NAME_COMMENT_EXIST);
	if (!ft_strchr(as->line, '"'))
		manage_error(as, &free_asm, as->line, NO_QUOTES);
	str = ft_strchr(as->line, '"') + 1;
	if (ft_strchr(str, '"') == NULL)
		manage_error(as, &free_asm, as->line, QUOTES_NOT_CLOSED);
	if ((ft_strcmp("", ft_strchr(str, '"') + 1) != 0))
		manage_error(as, &free_asm, as->line, STUFF_AFTER);
	if (!(str = ft_strsub(str, 0, ft_strchr(str, '"') - str)))
		manage_error(as, &free_asm, as->line, ERROR_MALLOC);
	if (choice == 1)
	{
		if (ft_strlen(str) > PROG_NAME_LENGTH)
			manage_error(as, &free_asm, as->line, NAME_TOO_LONG);
	}
	if (choice == 2)
	{
		if (ft_strlen(str) > COMMENT_LENGTH)
			manage_error(as, &free_asm, as->line, COMM_TOO_LONG);
	}
	*dst = str;
}

/*
** check_header() if there is no space in the header line, quit.
** if finds .name or .comment, parse string between quotes in our list.
*/

int		check_header(t_assembler *as)
{
	char	*len;
	char	*part;

	if ((len = ft_strchr(as->line, ' ')) == NULL)
		return (FAIL);
	if (!(part = ft_strsub(as->line, 0, len - as->line)))
		manage_error(as, &free_asm, as->line, ERROR_MALLOC);
	if (ft_strcmp(NAME_CMD_STRING, part) == 0)
	{
		ft_memdel((void**)&part);
		parse_header(as, &as->header->name, 1);
		return (SUCCESS);
	}
	else if (ft_strcmp(COMMENT_CMD_STRING, part) == 0)
	{
		ft_memdel((void**)&part);
		parse_header(as, &as->header->comment, 2);
		return (SUCCESS);
	}
	ft_memdel((void**)&part);
	return (FAIL);
}
