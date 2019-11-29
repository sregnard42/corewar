/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:04:29 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/29 14:06:45 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static int	bin(const char *format, ...)
{
	format += 0;
	return (0);
}

int			(*vm_print(t_vm *vm, unsigned int flag))(const char *format, ...)
{
	if (flag && !(vm->verbose & flag))
		return (&bin);
	if (vm->flags & VM_VISU)
		return (&printw);
	return (&ft_printf);
}
