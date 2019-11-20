/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:36:10 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/20 11:06:54 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void free_all(void *vm_ptr)
{
	t_vm	*vm;

	vm = (t_vm *)vm_ptr;
	champs_free(&vm->champs);
}


static void	vm_init(t_vm *vm, int ac, char **av)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->ac = --ac;
	vm->av = ++av;
	vm->exe = *--av;
	ft_bzero(&vm->champs, sizeof(t_champs));
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->verbose = 1;
}

int main(int ac, char **av)
{
	t_vm	vm;

	vm_init(&vm, ac, av);
	parse_args(&vm);
	arena_init(&vm);
	fight(&vm);
	free_all(&vm);
	return (1);
}
