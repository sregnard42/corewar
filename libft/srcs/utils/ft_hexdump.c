/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:57:51 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 15:03:52 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sum_line(char *content, int index, int size)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < 16 && index + i < size)
		sum += (unsigned char)content[index + i++];
	return (sum);
}

static void		print_line(char *content, int *index, int size)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	ft_printf("%07x ", *index);
	while (i < 16)
	{
		i > 0 ? ft_putchar(' ') : 0;
		if (*index + i < size)
			ft_printf("%02x", (unsigned char)content[*index + w++]);
		else
			ft_putstr("  ");
		++i;
	}
	ft_putln();
	*index += w;
}

void			ft_hexdump(char *content, int size)
{
	int index;

	index = 0;
	while (index < size)
	{
		if (sum_line(content, index, size))
			print_line(content, &index, size);
		else
		{
			print_line(content, &index, size);
			ft_putendl("*");
			while (!sum_line(content, index, size))
				index += 16;
		}
	}
	ft_printf("%07x\n", index);
}
