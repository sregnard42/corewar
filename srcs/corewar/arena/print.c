/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:47:50 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 14:49:21 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_visu(t_vm *vm, unsigned int cur, unsigned int len,
		unsigned int i)
{
	unsigned int	color;

	color = vm->colors_pc[i] ? vm->colors_pc[i] : vm->colors[i];
	color < 10 ?
		init_pair(color, color, -1) : init_pair(color, -1, color - 10);
	attron(COLOR_PAIR(color));
	printw("%02x", vm->arena[i++]);
	attroff(COLOR_PAIR(color));
	i - (cur * len) < len ? printw(" ") : printw("\n");
}

static void		print_dump(t_vm *vm, unsigned int cur, unsigned int len,
		unsigned int i)
{
	vm->print("%02x", vm->arena[i++]);
	i - (cur * len) < len ? vm->print(" ") : vm->print("\n");
}

static void		print_line(t_vm *vm, unsigned int cur, unsigned int len)
{
	unsigned int	i;
	void			(*f)(t_vm *, unsigned int, unsigned int, unsigned int);

	i = cur * len;
	f = (vm->flags & VM_VISU) ? &print_visu : &print_dump;
	while (i - (cur * len) < len)
		f(vm, cur, len, i++);
}

void			arena_print(t_vm *vm, unsigned int cols)
{
	unsigned int	cur;

	if (!vm)
		return ;
	cur = 0;
	while (cur < MEM_SIZE / cols)
		print_line(vm, cur++, cols);
	refresh();
	usleep(10000);
}
