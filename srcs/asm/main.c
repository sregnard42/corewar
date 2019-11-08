/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:14:04 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/08 10:43:03 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "asm.h"
/*
** open file and rewrite it in another file
*/

void	rewrite_file(char *line)
{
	int		fd;

	fd = open("test", O_RDWR | O_APPEND | O_CREAT, 0644);
	write(fd, line, ft_strlen(line));
}

int		open_file(int fd)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret != 0)
		{
			rewrite_file(line);
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
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	open_file(fd);
	return (0);
}
