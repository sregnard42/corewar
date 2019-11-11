/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:36:10 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/09 01:33:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	vm_init(t_vm *vm, int ac, char **av)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->ac = --ac;
	vm->av = ++av;
	vm->exe = *--av;
	vm->champs = ft_memalloc(sizeof(t_champs));
	if (!(vm->champs))
		ft_error(vm, &free_all, "vm_init memalloc\n");
}

void free_all(void *vm_ptr)
{
	t_vm	*vm;

	vm = (t_vm *)vm_ptr;
	ft_bzero(vm->arena, sizeof(char) * MEM_SIZE);
	champs_free(&(vm->champs));
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

	/*
	**	Testing structs
	*/
	champ_new(&vm);
	cmd_new(&vm);
	param_new(&vm);
	label_new(&vm);
	proc_new(&vm);
	free_all(&vm);
}
