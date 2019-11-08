/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:49:34 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/08 15:31:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_magic(int fd, int magic_number)
{
	unsigned char octets[4];
	octets[0] = magic_number >> 24;
	octets[1] = magic_number >> 16;
	octets[2] = magic_number >> 8;
	octets[3] = magic_number >> 0;
	write(fd, octets, 4);
}

void	write_name(int fd, char *name)
{
	int		len_name;
	int		len_reserved;
	char	*reserved;

	write_magic(fd, COREWAR_EXEC_MAGIC);
	len_name = ft_strlen(name);
	write(fd, name, len_name);
	len_reserved = PROG_NAME_LENGTH - len_name;
	reserved = ft_memalloc(sizeof(char) * len_reserved);
	write(fd, reserved, len_reserved);
	write(fd, "\0\0\0\0", 4);
	ft_memdel((void *)&reserved);
}

void	write_comment(int fd, char *comment)
{
	char	*to_fill;
	int		size_com;

	size_com = ft_strlen(comment);
	write(fd, "XXXX", 4); // pourquoi un 00 00 00 17 ?? prog_size
	write(fd, comment, size_com);
	to_fill = ft_memalloc(sizeof(char) * COMMENT_LENGTH - size_com);
	write(fd, to_fill, COMMENT_LENGTH - size_com);
	ft_memdel((void*)&to_fill);
}

char	*ft_strchr_plus_one(const char *s, int c)
{

	while (*s)
		if (*s == (unsigned char)c)
		{
			s++;
			return ((char *)s);
		}
		else
			s++;
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

int		size_string(char *name)
{
	int		i;

	i = 0;
	while (name[i] != '"')
		i++;
	return (i);
}

void	parse_name_comment(int fd, char *line)
{
	char *name;
	char *comment;

	name = NULL;
	comment = NULL;
	if (line[1] == 'n') //parse .name line
	{
		name = ft_strchr_plus_one(line, '"');
		if (!(name = ft_strsub(name, 0, size_string(name))))
			return ;
		write_name(fd, name);
	}
	if (line[1] == 'c')//parse .comment line
	{
		comment = ft_strchr_plus_one(line, '"');
		if (!(comment = ft_strsub(comment, 0, size_string(comment))))
			return ;
		write_comment(fd, comment);
	}
}
