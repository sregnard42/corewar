/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:36:10 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/07 14:03:43 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	vm_init(t_vm *vm)
{
	ft_bzero(vm, sizeof(t_vm));
	vm->champs = ft_memalloc(sizeof(t_champs));
	if (!(vm->champs))
		ft_error(vm, &free_all, "vm_init memalloc\n");
}

void free_all(void *vm_ptr)
{
	t_vm	*vm;

	vm = (t_vm *)vm_ptr;
	champs_free(&(vm->champs));
}

int main(int ac, char **av)
{
	t_vm	vm;

	if (!--ac)
		ft_error(NULL, NULL, "No argument !\n");
	vm_init(&vm);
	parse_args(&vm, ac, ++av);

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
		ft_printf("New test (MEM_SIZE = %d):\n", MEM_SIZE);
		arena_get(&vm, i);
		arena_set(&vm, i, c);
		arena_get(&vm, i);
		ft_putln();
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
