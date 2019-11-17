/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:47:55 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 16:58:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new parameter, which adds itself to a process's
**			parameters list
*/

t_param		*param_new(t_vm *vm)
{
	t_param	*param;

	if (!vm || !vm->champs.cur || !vm->champs.cur->procs.cur)
		ft_error(vm, &free_all, "param_new args\n");
	if (!(param = ft_memalloc(sizeof(t_param))))
		ft_error(vm, &free_all, "param_new memalloc\n");
	param->champ = vm->champs.cur;
	param->proc = param->champ->procs.cur;
	param->list = &param->proc->params;
	params_add(vm, param->list, param);
	return (param);
}
