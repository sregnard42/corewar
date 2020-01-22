/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:08:25 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 17:08:18 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose(t_vm *vm)
{
	!vm->ac-- ? error_usage(vm) : ++vm->av;
	ft_isinteger(*vm->av) ? vm->verbose = ft_atoi(*vm->av) : error_usage(vm);
	vm->verbose < 0 || vm->verbose > 15 ? error_usage(vm) : 0;
	vm->flags |= VM_VERBOSE;
}

static void	number(t_vm *vm)
{
	!vm->ac-- ? error_usage(vm) : ++vm->av;
	ft_isinteger(*vm->av) ? vm->number = ft_atoi(*vm->av) : error_usage(vm);
	vm->number < 1 ? error_usage(vm) : 0;
	vm->flags |= VM_NUMBER;
}

static void	dump(t_vm *vm)
{
	!vm->ac-- ? error_usage(vm) : ++vm->av;
	ft_isinteger(*vm->av) ? vm->dump = ft_atoi(*vm->av) : error_usage(vm);
	vm->flags |= VM_DUMP;
}

void		parse_option(t_vm *vm)
{
	char	*option;

	option = ++*vm->av;
	if (ft_strequ(option, "n"))
		number(vm);
	else if (ft_strequ(option, "v"))
		verbose(vm);
	else if (ft_strequ(option, "visu"))
		vm->flags |= VM_VISU;
	else if (ft_strequ(option, "dump"))
		dump(vm);
	else
		error_usage(vm);
	++vm->av;
}
