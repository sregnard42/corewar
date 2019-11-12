/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:36:24 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/12 13:30:56 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_too_small(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs.cur;
	ft_printf("ERROR: File %s is too small to be a champion\n", champ->file);
	ft_error(vm, &free_all, NULL);
}

void	error_prog_size(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs.cur;
	ft_printf("ERROR: File %s has too large a code ", champ->file);
	ft_printf("(%d bytes > %d bytes)\n", champ->prog_size, CHAMP_MAX_SIZE);
	ft_error(vm, &free_all, NULL);
}

void	error_magic(t_vm *vm)
{
	ft_printf("ERROR: File %s has an invalid header\n", vm->champs.cur->file);
	ft_error(vm, &free_all, NULL);
}

void	error_open(t_vm *vm, char *file)
{
	ft_printf("ERROR: Can't read source file %s\n", file);
	ft_error(vm, &free_all, NULL);
}

void	error_usage(t_vm *vm)
{
	char	**usage;

	usage = read_file(HELP_FILE);
	ft_print_tab(usage);
	ft_free_tab(&usage);
	ft_error(vm, &free_all, NULL);
}

