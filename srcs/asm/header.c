/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 10:49:34 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/08 14:26:33 by chrhuang         ###   ########.fr       */
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

	len_name = ft_strlen(name);
	write(fd, name, len_name);
	len_reserved = PROG_NAME_LENGTH - len_name;
	reserved = ft_memalloc(sizeof(char) * len_reserved);
	write(fd, reserved, len_reserved);
	write(fd, "\0\0\0\0", 4);
	ft_memdel((void *)&reserved);
}

void	write_header(int fd, char *name, char *comment)
{
	write_magic(fd, COREWAR_EXEC_MAGIC);
	write_name(fd, name);
	(void)comment;
	return ;
}
