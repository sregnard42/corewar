/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:44:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 16:02:12 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		parse_file(t_vm *vm, char *file)
{
	t_champ	*champ;
	int		fd;

	champ = NULL;
	(fd = open(file, O_RDONLY)) == -1 ? 
	ft_error(vm, &free_all, "file doesn't exist\n") : (champ = champ_new(vm));
	champ->file = file;
	champ->size = read(fd, champ->content, BUFF_SIZE);
	champ->size < FILE_MIN_SIZE ? error_too_small(vm) : 0;
	champ->content[champ->size] = '\0';
	ft_hexdump(champ->content, champ->size);
	parse_header(vm);
}

// TMP
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

void	error_usage(t_vm *vm)
{
	char	**usage;

	usage = read_file(HELP_FILE);
	ft_print_tab(usage);
	ft_free_tab(&usage);
	ft_error(vm, &free_all, NULL);
}

void		parse_args(t_vm *vm)
{
	!vm->ac ? error_usage(vm) : 0;
	while(vm->ac--)
	{
		ft_printf("[%s]\n", *vm->av);
		if (**vm->av == '-')
			parse_option(vm);
		else
			parse_file(vm, *vm->av++);
	}
	flags_status(vm);
}
