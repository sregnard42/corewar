/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:36:10 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/12 12:57:48 by sregnard         ###   ########.fr       */
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
}

int main(int ac, char **av)
{
	t_vm	vm;

	vm_init(&vm, ac, av);
	parse_args(&vm);
	arena_init(&vm);

	/*
	** Testing arena
	*/
	/*
	int				i;
	unsigned char	c;
	i = -2 * MEM_SIZE;
	c = 0;
	while (i <= 2 * MEM_SIZE)
	{
		arena_get(&vm, i);
		arena_set(&vm, i, c);
		arena_get(&vm, i);
		++i;
		c = c == 255 ? 1 : c + 1;
	}
	arena_print(&vm);
	*/

	free_all(&vm);
	return (1);
}
