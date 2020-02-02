/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:15:14 by lgaultie          #+#    #+#             */
/*   Updated: 2020/02/02 09:58:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	replace_by_spaces(t_assembler *as, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == COMMENT_CHAR || str[i] == ';')
			str[i] = '\0';
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i] == '"')
			return ;
		if (str[i] != ' ')
			manage_error(as, &free_asm, BAD_FORMAT);
		++i;
	}
}

void	change_sharp(t_assembler *as)
{
	char	*str;
	int		i;

	str = as->line;
	i = 0;
	while (str[i])
	{
		if (str[i] == COMMENT_CHAR || str[i] == ';')
		{
			str[i] = '\0';
			i = -1;
			while (as->line[++i])
				if (as->line[i] != ' ')
					return ;
			as->line[0] = '\0';
			return ;
		}
		i++;
	}
	i = -1;
	while (as->line[++i])
		if (as->line[i] != ' ')
			return ;
	as->line[0] = '\0';
}

char	*delete_space_after(t_assembler *as, char *str)
{
	char	*clean;
	int		i;

	if (!str)
		return (NULL);
	if ((clean = ft_strdup(str)) == NULL)
		manage_error(as, &free_asm, ERROR_MALLOC);
	i = ft_strlen(clean) - 1;
	if (i < 0)
		return (clean);
	while (clean[i] == ' ' || clean[i] == '\t')
		clean[i--] = '\0';
	return (clean);
}

void	check_before_dot(t_assembler *as, char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	if (str)
	{
		while (as->line && as->line[i] != '.')
		{
			if (as->line[i] != ' ' && as->line[i] != '\t')
				count++;
			i++;
		}
		if (count > 0)
			manage_error(as, &free_asm, BEFORE_DOT);
	}
}

void	change_sharp_after_quote(t_assembler *as)
{
	int		i;
	int		quote;

	i = -1;
	quote = 0;
	while (as->line[++i])
	{
		as->line[i] == '"' ? ++quote : 0;
		if (quote != 1 && (as->line[i] == COMMENT_CHAR || as->line[i] == ';'))
		{
			as->line[i] = '\0';
			i = -1;
			while (as->line[++i])
				if (as->line[i] != ' ')
					return ;
			as->line[0] = '\0';
			return ;
		}
	}
	i = -1;
	while (as->line[++i])
		if (as->line[i] != ' ')
			return ;
	as->line[0] = '\0';
}
