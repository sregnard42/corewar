/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 00:19:47 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/05 02:35:08 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		print_line(t_vm *vm, unsigned int cur, unsigned len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%02x", vm->arena[cur * len + i++]);
		i < len ? ft_printf(" ") : 0;
	}
	ft_printf("\n");
}

void		arena_print(t_vm *vm)
{
	unsigned int	len;
	unsigned int	cur;

	if (!vm)
		return ; 
	ft_printf("arena_print :\n");
	len = ft_sqrt(MEM_SIZE);
	cur = 0;
	while (cur < len)
	{
		print_line(vm, cur, len);
		++cur;
	}
}

unsigned char	arena_get(t_vm *vm, int index)
{
	ft_printf("arena_get : index before = %-4d\t", index);
	if (index >= MEM_SIZE)
		index %= MEM_SIZE;
	else if (index < 0)
		index = index % -MEM_SIZE + MEM_SIZE - 1;
	ft_printf("arena_get : index after = %-4d\t", index);
	if (index < 0 || index >= MEM_SIZE)
		ft_error(vm, &free_all, "ERROR: arena_get out of bounds\n");
	ft_printf("arena_get : vm->arena[%d] = %02x\n", index, vm->arena[index]);
	return (vm->arena[index]);
}

void			arena_set(t_vm *vm, int index, unsigned char c)
{
	ft_printf("arena_set : index before = %-4d\t", index);
	if (index >= MEM_SIZE)
		index %= MEM_SIZE;
	else if (index < 0)
		index = index % -MEM_SIZE + MEM_SIZE - 1;
	ft_printf("arena_set : index after = %-4d\t", index);
	if (index < 0 || index >= MEM_SIZE)
		ft_error(vm, &free_all, "ERROR: arena_set out of bounds\n");
	vm->arena[index] = c;
 	ft_printf("arena_set : vm->arena[%d] = %02x\n", index, vm->arena[index]);
}
