/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:37:26 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/05 16:56:19 by lgaultie         ###   ########.fr       */
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
//a mettre en anglais:
//si on trouve pas de " dans la ligne ->error
// on chope la partie apres la premiere "
// si il y a pas une deuxieme " -->error
// on reverifie si il y a bien une deuxieme " (verif obligatoire pour -q),
// et on regarde ce quil y apres
// alors on va choper ce qui est entre parenthese, mais pas si
// il y a eu une erreur, parceque la size du malloc sera caca, dans ce
// je fais un malloc vide pour empecher les breakfree
*/

void	parse_header(t_assembler *as, char **dst, int choice)
{
	char	*str;
	int		error;

	error = 0;
	if (dst && *dst)
		manage_error(as, &free_asm, as->epure_line, NAME_COMMENT_EXIST);
		//si on trouve pas de " dans la ligne ->error
	if (!ft_strchr(as->line, '"'))
		manage_error(as, &free_asm, as->epure_line, NO_QUOTES);
	// on chope la partie apres la premiere "
	str = ft_strchr(as->line, '"') + 1;
	// si il y a pas une deuxieme " -->error
	if (ft_strchr(str, '"') == NULL)
		manage_error(as, &free_asm, as->epure_line, QUOTES_NOT_CLOSED);
	// on reverifie si il y a bien une deuxieme " (verif obligatoire pour -q),
	if (!(ft_strchr(str, '"')))
		error = 1;
	// et on regarde ce quil y apres
	if (error == 0 && (ft_strcmp("", ft_strchr(str, '"') + 1) != 0))
		manage_error(as, &free_asm, as->epure_line, STUFF_AFTER);
	// alors on va choper ce qui est entre parenthese, mais pas si
	// il y a eu une erreur, parceque la size du malloc sera caca, dans ce
	// je fais un malloc vide pour empecher les breakfree
	if (error == 0)
	{
		if (!(str = ft_strsub(str, 0, ft_strchr(str, '"') - str)))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
	else
	{
		if (!(str = ft_strdup("")))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
	if (choice == 1)
	{
		if (ft_strlen(str) > PROG_NAME_LENGTH)
			manage_error(as, &free_asm, as->epure_line, NAME_TOO_LONG);
	}
	if (choice == 2)
	{
		if (ft_strlen(str) > COMMENT_LENGTH)
			manage_error(as, &free_asm, as->epure_line, COMM_TOO_LONG);
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
		manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
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
