/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:44:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/09 01:33:34 by sregnard         ###   ########.fr       */
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
//	ft_hexdump(vm->champs->cur->content, ret);
}

static void flags_status(t_vm *vm)
{
	vm->flags & VM_A ? ft_printf("-a activated\n") : 0;
	if (vm->flags & VM_D)
	{
		ft_printf("-d activated\t");
		ft_printf("vm->dump = %d\n", vm->dump);
	}
	if (vm->flags & VM_S)
	{
		ft_printf("-s activated\t");
		ft_printf("vm->dump = %d\n", vm->dump);
	}
	if (vm->flags & VM_V)
	{
		ft_printf("-v activated\t");
		ft_printf("vm->verbose = %d\n", vm->verbose);
		ft_printf("[\n");
		!vm->verbose ? ft_printf("\tShow only essentials\n") : 0;
		vm->verbose & V_LIVES ? ft_printf("\tShow lives\n") : 0;
		vm->verbose & V_CYCLES ? ft_printf("\tShow cycles\n") : 0;
		vm->verbose & V_OPERATIONS ? ft_printf("\tShow operations\n") : 0;
		vm->verbose & V_DEATHS ? ft_printf("\tShow deaths\n") : 0;
		vm->verbose & V_MOVES ? ft_printf("\tShow PC movements\n") : 0;
		ft_printf("]\n");
	}
	vm->flags & VM_B ? ft_printf("-b activated\n") : 0;
	vm->flags & VM_N ? ft_printf("-n activated\n") : 0;
	vm->flags & VM_STEALTH ? ft_printf("--stealth activated\n") : 0;
}

void	usage(t_vm *vm)
{
	char	**usage;

	usage = read_file(HELP_FILE);
	ft_print_tab(usage);
	ft_free_tab(&usage);
	ft_error(vm, &free_all, NULL);
}

void		parse_args(t_vm *vm)
{
	!vm->ac ? usage(vm) : 0;
	ft_printf("Parsing : ");
	while(vm->ac--)
	{
		ft_printf("[%s]", *vm->av);
		if (**vm->av == '-')
			parse_option(vm);
		else
			parse_file(vm, *vm->av++);
	}
	ft_putln();
	flags_status(vm);
}
