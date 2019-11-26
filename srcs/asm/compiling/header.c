/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:49:34 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/26 14:50:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_big_endian1(int fd, int magic_number)
{
	unsigned char	octets[4];

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

	write_big_endian1(fd, COREWAR_EXEC_MAGIC);
	len_name = ft_strlen(name);
	write(fd, name, len_name);
	len_reserved = PROG_NAME_LENGTH - len_name;
	reserved = ft_memalloc(sizeof(char) * len_reserved);
	write(fd, reserved, len_reserved);
	ft_memdel((void *)&reserved);
}

void	write_comment(t_assembler *as, int fd, char *comment)
{
	char	*to_fill;
	int		size_com;

	write(fd, "\0\0\0\0", 4);
	size_com = ft_strlen(comment);
	write_big_endian1(fd, as->prog_size); // pas la bonne valeur
	write(fd, comment, size_com);
	to_fill = ft_memalloc(sizeof(char) * COMMENT_LENGTH - size_com);
	write(fd, to_fill, COMMENT_LENGTH - size_com);
	write(fd, "\0\0\0\0", 4);
	ft_memdel((void*)&to_fill);
}

void	write_header(t_assembler *as, int fd)
{
	write_name(fd, as->header->name);
	write_comment(as, fd, as->header->comment);
}
