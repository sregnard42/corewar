/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 18:46:17 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 15:47:09 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_reg(t_vm *vm, t_reg *reg)
{
	int val;

	val = 0;
	regcpy(&val, reg, sizeof(int));
	vm->print("reg value: %d\n", val);
}

int			is_reg(int id)
{
	return (id >= 1 && id <= REG_NUMBER);
}

void		regcpy(void *dst, const void *src, size_t n)
{
	(n > REG_SIZE) ? ft_memcpy(dst, src, REG_SIZE) : ft_memcpy(dst, src, n);
}
