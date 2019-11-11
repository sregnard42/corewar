/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 23:08:25 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 16:00:34 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	verbose (t_vm *vm)
{
	!vm->ac-- ? error_usage(vm) : 0;
	++vm->av;
	ft_isinteger(*vm->av) ? vm->verbose = ft_atoi(*vm->av) : error_usage(vm);
	vm->verbose > 31 ?
	ft_error(vm, &free_all, "-v, value must be inside [0, 31]\n") : 0;
	vm->flags |= VM_V;
}

static void	dump_repeat(t_vm *vm)
{
	!vm->ac-- ? error_usage(vm) : 0;
	++vm->av;
	ft_isinteger(*vm->av) ? vm->dump = ft_atoi(*vm->av) : error_usage(vm);
	vm->flags |= VM_S;
}

static void	dump(t_vm *vm)
{
	!vm->ac-- ? error_usage(vm) : 0;
	++vm->av;
	ft_isinteger(*vm->av) ? vm->dump = ft_atoi(*vm->av) : error_usage(vm);
	vm->flags |= VM_D;
}

void		parse_option(t_vm *vm)
{
	char	*option;

	option = ++*vm->av;
	if (*option == 'a')
		vm->flags |= VM_A;
	else if (*option == 'd')
		dump(vm);
	else if (*option == 's')
		dump_repeat(vm);
	else if (*option == 'v')
		verbose(vm);
	else if (*option == 'b')
		vm->flags |= VM_B;
	else if (*option == 'n')
		vm->flags |= VM_N;
	else if (ft_strequ(++option, "stealth"))
		vm->flags |= VM_STEALTH;
	else 
		error_usage(vm);
	++vm->av;
}

