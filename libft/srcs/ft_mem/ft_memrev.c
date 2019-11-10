/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:47:17 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 13:31:14 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memrev(void *p, size_t n)
{
	unsigned char	*c;
//	unsigned char	swap;
	size_t			i;

	c = (unsigned char *)p;
	i = 0;
	ft_printf("ft_memrev:\n");
	while (i < n)
	{
		ft_printf("c[%d] = %02x\n", i, c[i]);
		++i;
	}
	ft_putln();
	i = 0;
	while (i < n)
	{
		ft_printf("Before\tc[%d] = %02x & c[%d] = %02x\n", i, c[i], n - 1, c[n - 1]);
		ft_memswap(c + i, c + n - 1, sizeof(unsigned char));
		/*
		swap = c[i];
		c[i] = c[n - 1];
		c[n - 1] = swap;
		*/
		ft_printf("After\tc[%d] = %02x & c[%d] = %02x\n", i, c[i], n - 1, c[n - 1]);
		++i;
		--n;
	}
}
