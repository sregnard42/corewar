/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/08 15:22:35 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		open_file(int fd)
{
	char	*line;
	int		ret;
	int		fd1;

	ret = 1;
	fd1 = open("test", O_RDWR | O_APPEND | O_CREAT, 0644);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret != 0)
		{
			//parsing avec aucune verif
			if (line[0] == '.')
				parse_name_comment(fd1, line);
			ft_memdel((void*)&line);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;

	if (argc > 2 || argc == 1)
	{
		ft_putstr("Usage: ./asm mychampion.s\n");
		return (0);
	}
	argv += 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	open_file(fd);
	// fd = open("tmp", O_RDWR | O_APPEND | O_CREAT, 0644);
	// write_header(fd, "zork", "just a basic living prog");
	return (0);
}
