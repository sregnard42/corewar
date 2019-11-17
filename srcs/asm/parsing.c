/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:18:43 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/17 15:41:35 by chrhuang         ###   ########.fr       */
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

void	parse_header(t_assembler *as, char *line, char **dst)
{
	char *str;

	if (dst && *dst)
		ft_error(as, &free_asm, NAME_COMMENT_EXIST);
	str = ft_strchr(line, '"') + 1;
	if (!(str = ft_strsub(str, 0, ft_strchr(str, '"') - str)))
		ft_error(as, &free_asm, "Malloc failed\n");
	*dst = str;
}

void	parse_instruction(t_assembler *as, char *line)
{
	char	**tab;

	(void)as;
	clean_line(line);
	if (!(tab = ft_strsplit(line, ' ')))
		return ;
	ft_print_tab(tab);
	ft_putendl("----------------");
}

int		check_header(t_assembler *as, char *line)
{
	char	*len;

	if ((len = ft_strchr(line, ' ')) == NULL)
		return (0);
	clean_line(line);
	if (ft_strcmp(NAME_CMD_STRING, ft_strsub(line, 0, len - line)))
	{
		parse_header(as, line, &as->header->name);
		return (1);
	}
	else if (ft_strcmp(COMMENT_CMD_STRING, ft_strsub(line, 0, len - line)))
	{
		parse_header(as, line, &as->header->comment);
		return (1);
	}
	return (0);
}

void	parsing(t_assembler *as)
{
	int		ret;
	int		fd;
	char	*line;

	ret = 1;
	fd = as->source_fd;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		// ft_printf("popopopo = %d\n", ft_strchr(line, ' ') - line);
		if (check_header(as, line) == 0)
			parse_instruction(as, line);
		// if (ft_strcmp(NAME_CMD_STRING, ft_strsub(line, 0, ft_strchr(line, ' ') - line)) == 0)
		// 	parse_header(as, line, &as->header->name);
		// else if (ft_strncmp(COMMENT_CMD_STRING, line, ft_strlen(COMMENT_CMD_STRING)) == 0)
		// 	parse_header(as, line, &as->header->comment);
		else
		ft_memdel((void*)&line);
	}
	ft_printf("\n\nParsing end\n\n");
	ft_printf("name = %s\ncomment = %s\n", as->header->name, as->header->comment);
}
