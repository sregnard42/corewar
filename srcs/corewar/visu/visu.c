/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:19:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/29 14:20:18 by sregnard         ###   ########.fr       */
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


void	wait_input(void)
{
	printw("Press any key to continue...");
	getch();
	clrtoeol();
}

void	visu_init(t_vm *vm)
{
	vm->print = vm_print(vm, 0);
	if (!(vm->flags & VM_VISU))
		return ;
	initscr();
	start_color();
	use_default_colors();
	curs_set(FALSE);
}

