/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/04 23:56:03 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	vm_init(t_vm *vm)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->champs = ft_memalloc(sizeof(t_champs));
}

void free_all(void *vm_ptr)
{
	t_vm	*vm;

	ft_printf("free_all\n");
	vm = (t_vm *)vm_ptr;
	champs_free(&(vm->champs));
	return ;
}

int main()
{
	t_vm	vm;

	vm_init(&vm);
	champ_new(&vm);
	champ_new(&vm);
	vm.champs->first->name = ft_strdup("Je vis");
	vm.champs->first->next->name = ft_strdup("Je vis aussi");
	ft_printf("%s\n", vm.champs->first->name);
	ft_printf("%s\n", vm.champs->first->next->name);
	label_new(&vm, NULL);
	cmd_new(&vm);
	proc_new(&vm);
}
