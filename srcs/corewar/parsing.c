/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:44:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 18:27:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		parse_file(t_vm *vm, char *file)
{
	int		fd;
	int		ret;

	(fd = open(file, O_RDONLY)) == -1 ? 
	ft_error(vm, &free_all, "file doesn't exist\n") : champ_new(vm);
	ret = read(fd, vm->champs->cur->content, BUFF_SIZE);
	ret < 1 ? ft_error(vm, &free_all, "empty file\n") : 0;
	vm->champs->cur->content[ret] = '\0';
	ft_hexdump(vm->champs->cur->content, ret);
}

void		parse_args(t_vm *vm, int ac, char **av)
{
	while(ac--)
		parse_file(vm, *av++);
}
