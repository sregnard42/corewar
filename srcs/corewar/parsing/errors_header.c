/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_header.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:52:24 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 15:52:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_too_small(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs.cur;
	ft_printf("ERROR: File %s is too small to be a champion\n", champ->file);
	ft_error(vm, &vm_free, NULL);
}

void	error_prog_size(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs.cur;
	if (champ->prog_size == 0)
		ft_printf("ERROR: File %s has no code\n", champ->file);
	else
	{
		ft_printf("ERROR: File %s has too large a code ", champ->file);
		ft_printf("(%d bytes > %d bytes)\n", champ->prog_size, CHAMP_MAX_SIZE);
	}
	ft_error(vm, &vm_free, NULL);
}

void	error_magic(t_vm *vm)
{
	ft_printf("ERROR: File %s has an invalid header\n", vm->champs.cur->file);
	ft_error(vm, &vm_free, NULL);
}

void	error_name(t_vm *vm)
{
	ft_printf("ERROR: File %s has an invalid name length\n",
			vm->champs.cur->file);
	ft_error(vm, &vm_free, NULL);
}

void	error_comment(t_vm *vm)
{
	ft_printf("ERROR: File %s has an invalid comment length\n",
			vm->champs.cur->file);
	ft_error(vm, &vm_free, NULL);
}
