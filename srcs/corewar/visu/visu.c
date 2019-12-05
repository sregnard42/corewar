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

/*
**			Does nothing (on purpose), only its existence is useful
*/

static int	bin(const char *format, ...)
{
	format += 0;
	return (0);
}

/*
**			Takes vm and a flag as parameters, (0 = no flag)
**			Returns function pointer
**			&bin if flag is not activated in vm
**			&printw if flag is activated and VM_VISU is activated too
**			&ft_printf if flag is activated and VM_VISU isn't
*/

int			(*vm_print(t_vm *vm, unsigned int flag))(const char *format, ...)
{
	if (flag && !(vm->verbose & flag))
		return (&bin);
	if (vm->flags & VM_VISU)
		return (&printw);
	return (&ft_printf);
}

/*
**			Program pauses until the user press a button
**			Clear printed line once a button has been pressed
*/

void		wait_input(void)
{
	printw("Press any key to continue...");
	getch();
	clrtoeol();
}

/*
**			Set vm->print to either &ft_printf or &printw
**			If VM_VISU is activated call functions from <ncurses.h> to
**			init terminal window
*/

void		visu_init(t_vm *vm)
{
	vm->print = vm_print(vm, 0);
	if (!(vm->flags & VM_VISU))
		return ;
	initscr();
	start_color();
	use_default_colors();
	curs_set(FALSE);
}

