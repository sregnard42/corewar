/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:03:38 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 18:14:09 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new argeter, which adds itself to a process's
**			argeters list
*/

t_arg		*arg_new(t_vm *vm)
{
	t_arg	*arg;

	if (!vm || !vm->champs.cur || !vm->procs.cur)
		ft_error(vm, &vm_free, "arg_new args\n");
	if (!(arg = ft_memalloc(sizeof(t_arg))))
		ft_error(vm, &vm_free, "arg_new memalloc\n");
	arg->champ = vm->champs.cur;
	arg->proc = vm->procs.cur;
	arg->list = &arg->proc->args;
	args_add(vm, arg->list, arg);
	return (arg);
}
