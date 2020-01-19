/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:27:54 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 16:14:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b, size_t n)
{
	unsigned char	*ca;
	unsigned char	*cb;
	unsigned char	swap;

	ca = (unsigned char *)a;
	cb = (unsigned char *)b;
	while (n--)
	{
		swap = ca[n];
		ca[n] = cb[n];
		cb[n] = swap;
	}
}
