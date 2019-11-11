/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:50:40 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 15:55:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_too_small(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs->cur;
	ft_printf("ERROR: File %s is too small to be a champion\n", champ->file);
	ft_error(vm, &free_all, NULL);
}

void	error_prog_size(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs->cur;
	ft_printf("ERROR: File %s has too large a code ", champ->file);
	ft_printf("(%d bytes > %d bytes)\n", champ->prog_size, CHAMP_MAX_SIZE);
	ft_error(vm, &free_all, NULL);
}

void	error_magic(t_vm *vm)
{
	ft_printf("ERROR: File %s has an invalid header\n", vm->champs->cur->file);
	ft_error(vm, &free_all, NULL);
}

void	parse_header(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs->cur;
	ft_memcpy(&champ->magic, champ->content, sizeof(int));
	ft_memrev(&champ->magic, sizeof(int));
	if (champ->magic != COREWAR_EXEC_MAGIC)
		error_magic(vm);
	champ->cursor += sizeof(int);
	ft_memcpy(&champ->name, champ->content + champ->cursor, PROG_NAME_LENGTH);
	champ->cursor += PROG_NAME_LENGTH + PADDING;
	ft_memcpy(&champ->prog_size, champ->content + champ->cursor, sizeof(unsigned int));
	ft_memrev(&champ->prog_size, sizeof(unsigned int));
	if (champ->prog_size > CHAMP_MAX_SIZE)
		error_prog_size(vm);
	champ->cursor += sizeof(unsigned int);
	ft_memcpy(&champ->comment, champ->content + champ->cursor, COMMENT_LENGTH);
	champ->cursor += COMMENT_LENGTH + PADDING;
	champ_print(champ);
}
