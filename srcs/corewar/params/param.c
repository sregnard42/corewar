/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:47:55 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/12 13:51:38 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Creates a new parameter, which adds itself to a commands's
**			parameters list
*/

t_param		*param_new(t_vm *vm)
{
	t_param	*param;

	if (!vm || !vm->champs.cur || !vm->champs.cur->cmds.cur)
		ft_error(vm, &free_all, "param_new args\n");
	if (!(param = ft_memalloc(sizeof(t_param))))
		ft_error(vm, &free_all, "param_new memalloc\n");
	params_add(vm, &vm->champs.cur->cmds.cur->params, param);
	return (param);
}

/*
**			Frees a parameter
*/

void		param_free(t_param **param)
{
	ft_memdel((void **)param);
}
