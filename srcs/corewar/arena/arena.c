/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:19:47 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/20 12:26:05 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_line(t_vm *vm, unsigned int cur, unsigned int len)
{
	unsigned int	i;
	unsigned int	color;

	i = cur * len;
	while (i - (cur * len) < len)
	{
		color = vm->colors[i] + 30;
		ft_printf("\033[1;%dm", color);
		ft_printf("%02x", vm->arena[i++]);
		ft_printf("\033[0m");
		i - (cur * len) < len ? ft_printf(" ") : 0;
	}
	ft_putln();
}

void		arena_print(t_vm *vm, unsigned int cols)
{
	unsigned int	cur;

	if (!vm)
		return ; 
	cur = 0;
	system("clear");
	while (cur < MEM_SIZE / cols)
		print_line(vm, cur++, cols);
}

unsigned char	arena_get(t_vm *vm, int index)
{
	if (index >= MEM_SIZE)
		index %= MEM_SIZE;
	else if (index < 0)
		index = index % -MEM_SIZE + MEM_SIZE - 1;
	if (index < 0 || index >= MEM_SIZE)
		ft_error(vm, &free_all, "arena_get out of bounds\n");
	return (vm->arena[index]);
}

void			arena_set(t_vm *vm, int index, unsigned char c)
{
	if (index >= MEM_SIZE)
		index %= MEM_SIZE;
	else if (index < 0)
		index = index % -MEM_SIZE + MEM_SIZE - 1;
	if (index < 0 || index >= MEM_SIZE)
		ft_error(vm, &free_all, "arena_set out of bounds\n");
	vm->arena[index] = c;
}

void			arena_init(t_vm *vm)
{
	unsigned int	nb_players;
	t_champ			*champ;

	nb_players = vm->champs.size;
	champ = vm->champs.first;
	while (champ)
	{
		champ->pos = (champ->id - 1) * (MEM_SIZE / nb_players);
		ft_memcpy(&vm->arena[champ->pos], &champ->content[champ->cursor], champ->prog_size);
		ft_memset(&vm->colors[champ->pos], champ->id, champ->prog_size);
		vm->champs.cur = champ;
		proc_new(vm);
		champ = champ->next;
	}
}
