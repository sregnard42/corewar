/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/03 15:51:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	vm_init(t_vm *vm)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->champs = ft_memalloc(sizeof(t_champs));
}

void free_all(void *vm)
{
	vm += 0;
	ft_printf("free all\n");
	return ;
}

int main()
{
	t_vm	vm;

	vm_init(&vm);
	champ_new(&vm);
	vm.champs->first->name = ft_strdup("Je vis");
	ft_printf("%s\n", vm.champs->first->name);
	label_new(&vm, NULL);
	cmd_new(&vm);
	proc_new(&vm);
}
