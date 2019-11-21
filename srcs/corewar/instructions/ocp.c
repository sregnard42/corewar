/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:48:56 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 14:34:48 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Checks one bit
*/

static int	get_bit(unsigned int ocp, int nb)
{
	return (ocp & (1 << (nb)));
}

/*
**			Checks two bits
*/

static int	get_type(unsigned int ocp, int nb)
{
	int		bit[2];

	bit[0] = get_bit(ocp, sizeof(unsigned int) - nb * 2);
	bit[1] = get_bit(ocp, sizeof(unsigned int) - nb * 2 + 1);
	if (!bit[1] && bit[0])
		return (REG_CODE);
	if (bit[1] && !bit[0])
		return (DIR_CODE);
	if (bit[1] && bit[0])
		return (IND_CODE);
	return (0);
}

void		get_val(t_vm *vm, t_arg *arg, int opcode)
{
	int	size;
	
	size = 0;
	if (arg->type == REG_CODE)
		size = REG_SIZE;
	else if (arg->type == DIR_CODE)
		if (opcode == ZJMP || opcode == LDI || opcode == STI || opcode == FORK)
			size = DIR_SIZE / 2;
		else
			size = DIR_SIZE;
	else if (arg->type == IND_CODE)
		size = IND_SIZE;
	ft_memcpy(&arg->val, vm->arena + arg->proc->pc, size);
	ft_memrev(&arg->val, size);
	proc_set_pc(vm, arg->proc, arg->proc->pc + size);
}

/*
**			Creates and adds an arg to the list if exists 
*/

static void	add_arg(t_vm *vm, int opcode, unsigned int ocp, int nb)
{
	t_arg			*arg;
	int				type;

	type = get_type(ocp, nb - 1);
	if (type == 0)
		return ;
	arg = arg_new(vm);
	arg->type = type; 
	get_val(vm, arg, opcode);
}

/*
**			Returns arguments of an instruction needed by a process
*/

void		ocp(t_vm *vm, int opcode)
{
	t_process		*proc;
	unsigned int	ocp;
	int				nb;

	proc = vm->champs.cur->procs.cur;
	if (opcode == LIVE || opcode == ZJMP || opcode == FORK || opcode == LFORK)
		return ;
	ocp = arena_get(vm, proc->pc);
	proc_set_pc(vm, proc, proc->pc + 1);
	nb = 0;
	while (nb < MAX_ARGS_NUMBER)
		add_arg(vm, opcode, ocp, nb++);
}
