/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:36:24 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/20 11:04:24 by sregnard         ###   ########.fr       */
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
	ft_printf("ERROR: File %s has too large a code ", champ->file);
	ft_printf("(%d bytes > %d bytes)\n", champ->prog_size, CHAMP_MAX_SIZE);
	ft_error(vm, &vm_free, NULL);
}

void	error_magic(t_vm *vm)
{
	ft_printf("ERROR: File %s has an invalid header\n", vm->champs.cur->file);
	ft_error(vm, &vm_free, NULL);
}

void	error_open(t_vm *vm, char *file)
{
	ft_printf("ERROR: Can't read source file %s\n", file);
	ft_error(vm, &vm_free, NULL);
}

void	error_usage(t_vm *vm)
{
	ft_printf("usage: %s %s", vm->exe, USAGE);
	ft_printf("\n##### OPTIONS #####\n\n");
	ft_printf("%-6s: %s", "-visu", VISU);
	ft_printf("%-6s: %s", "-dump", DUMP);
	ft_printf("%-6s: %s", "-n", NUMBER);
	ft_printf("%-6s: %s", "-v", VERBOSE);
	ft_printf("\t%-6s: %s", "- 0", VERBOSE_0);
	ft_printf("\t%-6s: %s", "- 1", VERBOSE_1);
	ft_printf("\t%-6s: %s", "- 2", VERBOSE_2);
	ft_printf("\t%-6s: %s", "- 4", VERBOSE_4);
	ft_printf("\t%-6s: %s", "- 8", VERBOSE_8);
	ft_printf("\t%-6s: %s", "- 16", VERBOSE_16);
	ft_error(vm, &vm_free, NULL);
}

