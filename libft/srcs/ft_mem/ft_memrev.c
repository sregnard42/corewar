/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:47:17 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 14:47:29 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memrev(void *p, size_t n)
{
	unsigned char	*c;
	size_t			i;

	c = (unsigned char *)p;
	i = 0;
	while (i < n)
		ft_memswap(c + i++, c + n-- - 1, sizeof(unsigned char));
}
