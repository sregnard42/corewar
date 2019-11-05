/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/05 02:33:54 by sregnard         ###   ########.fr       */
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

	vm = (t_vm *)vm_ptr;
	champs_free(&(vm->champs));
}

int main()
{
	t_vm	vm;
	int				i;
	unsigned char	c;

	vm_init(&vm);
	i = -2 * MEM_SIZE;
	c = 0;
	while (i <= 2 * MEM_SIZE)
	{
		ft_printf("New test (MEM_SIZE = %d):\n", MEM_SIZE);
		arena_get(&vm, i);
		arena_set(&vm, i, c);
		arena_get(&vm, i);
		ft_putln();
		++i;
		c = c == 255 ? 1 : c + 1;
	}
	arena_print(&vm);

	/*
	champ_new(&vm);
	champ_new(&vm);
	label_new(&vm, NULL);
	cmd_new(&vm);
	proc_new(&vm);
	*/

}
