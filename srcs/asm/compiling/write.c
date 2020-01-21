/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:36:01 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 17:12:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** write_big_endian() change order of bytes to big endian, depending of size
** only write the 2 first bytes or 4 of them.
*/

void			write_big_endian(t_assembler *as, int nb, int size)
{
	unsigned char octets[4];

	octets[0] = nb >> 24;
	octets[1] = nb >> 16;
	octets[2] = nb >> 8;
	octets[3] = nb >> 0;
	if (size == IND_SIZE)
	{
		write(as->cor_fd, &octets[2], 1);
		write(as->cor_fd, &octets[3], 1);
	}
	if (size == DIR_SIZE)
		write(as->cor_fd, octets, size);
}

/*
** write_register()
*/

void			write_register(t_assembler *as, char *param)
{
	int		ret;

	param++;
	ret = ft_atoi(param);
	write(as->cor_fd, &ret, RID_SIZE);
}

static void		write_neg_number2(t_assembler *as, int size,
			unsigned char octets[4])
{
	if (size == IND_SIZE)
	{
		if (octets[3] == 0)
		{
			octets[2] += 1;
			write(as->cor_fd, &octets[2], 1);
		}
		else
			write(as->cor_fd, &octets[2], 1);
		write(as->cor_fd, &octets[3], 1);
	}
	if (size == DIR_SIZE)
	{
		write(as->cor_fd, octets, size);
	}
}

/*
** write_neg_number() change order of bytes in big endian, then reverse all
** bit (ex: if it was 0, become 1) to express negative number.
** add 1 to octets[3] to write another 1 at the begginning. Depending of size
** only write the 2 first bytes or 4 of them.
*/

void			write_neg_number(t_assembler *as, int nb, int size)
{
	unsigned char	octets[4];
	unsigned char	max;

	max = 0xff;
	octets[0] = nb >> 24;
	octets[1] = nb >> 16;
	octets[2] = nb >> 8;
	octets[3] = nb >> 0;
	octets[0] = octets[0] ^ max;
	octets[1] = octets[1] ^ max;
	octets[2] = octets[2] ^ max;
	octets[3] = octets[3] ^ max;
	octets[3] += 1;
	write_neg_number2(as, size, octets);
}
