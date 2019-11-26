/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:37:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/26 14:26:55 by lgaultie         ###   ########.fr       */
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
** are too long or checks if invalid input after the name or
** comment (ex: .name "oui"non)
*/

void	parse_header(t_assembler *as, char *line, char **dst, int choice)
{
	char *str;

	if (dst && *dst)
		ft_error(as, &free_asm, NAME_COMMENT_EXIST);
	str = ft_strchr(line, '"') + 1;
	if ((ft_strcmp("", ft_strchr(str, '"') + 1) != 0))
		ft_error(as, &free_asm, STUFF_AFTER);
	if (!(str = ft_strsub(str, 0, ft_strchr(str, '"') - str)))
		ft_error(as, &free_asm, ERROR_MALLOC);
	if (choice == 1)
	{
		if (ft_strlen(str) > PROG_NAME_LENGTH)
			ft_error(as, &free_asm, NAME_TOO_LONG);
	}
	if (choice == 2)
	{
		if (ft_strlen(str) > COMMENT_LENGTH)
			ft_error(as, &free_asm, COMM_TOO_LONG);
	}
	*dst = str;
}

/*
** check_header() if there is no space, quit
** if finds .name or .comment, parse string between quotes in our list.
*/

int		check_header(t_assembler *as, char *line)
{
	char	*len;
	char	*part;

	if ((len = ft_strchr(line, ' ')) == NULL)
		return (0);
	clean_line(line);
	part = ft_strsub(line, 0, len - line);
	if (ft_strcmp(NAME_CMD_STRING, part) == 0)
	{
		ft_memdel((void**)&part);
		parse_header(as, line, &as->header->name, 1);
		return (1);
	}
	else if (ft_strcmp(COMMENT_CMD_STRING, part) == 0)
	{
		ft_memdel((void**)&part);
		parse_header(as, line, &as->header->comment, 2);
		return (1);
	}
	ft_memdel((void**)&part);
	return (0);
}
