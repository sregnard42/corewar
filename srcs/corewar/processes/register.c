/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:46:17 by sregnard          #+#    #+#             */
/*   Updated: 2019/12/09 19:10:18 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			is_reg(int id)
{
	return (id >= 1 && id <= REG_NUMBER);
}

void		regcpy(void *dst, const void *src, size_t n)
{
	(n > REG_SIZE) ? ft_memcpy(dst, src, REG_SIZE) : ft_memcpy(dst, src, n);
}
