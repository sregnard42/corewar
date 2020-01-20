/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:38:05 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 15:38:02 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	get_val_dir(t_vm *vm, t_arg *arg, int *val)
{
	int			opcode;

	opcode = arena_get(vm, vm->pc);
	if (opcode == ZJMP || opcode == LDI || opcode == LLDI ||
			opcode == STI || opcode == FORK || opcode == LFORK)
		*val = (short int)arg->val;
	else
		*val = arg->val;
}

static void	get_val_ind(t_vm *vm, t_arg *arg, int *val, int modulo)
{
	int			opcode;

	opcode = arena_get(vm, vm->pc);
	if (opcode == ST)
		*val = arg->val % IDX_MOD;
	else
	{
		if (modulo)
			arena_load(vm, vm->pc + (short int)arg->val % IDX_MOD,
					val, sizeof(int));
		else
			arena_load(vm, vm->pc + (short int)arg->val, val, sizeof(int));
	}
}

/*
**		Gets the actual value of an argument depending on its type
**		REG_CODE returns the value inside of the registry
**		DIR_CODE returns the value as is
**		IND_CODE returns the value stocked at given address in the arena
**		Returns 0 if register is invalid, 1 in all other cases
*/

int			get_val(t_vm *vm, t_arg *arg, int *val, int modulo)
{
	t_process	*proc;

	if (!arg)
		return (0);
	proc = vm->procs.cur;
	ft_bzero(val, sizeof(int));
	if (arg->type == REG_CODE)
	{
		if (!is_reg(arg->val))
			return (0);
		regcpy(val, &proc->reg[arg->val], sizeof(int));
	}
	else if (arg->type == DIR_CODE)
		get_val_dir(vm, arg, val);
	else if (arg->type == IND_CODE)
		get_val_ind(vm, arg, val, modulo);
	return (1);
}

/*
**      Loads a value inside a registry
*/

void		load(t_vm *vm, int reg, int val)
{
	t_process	*proc;

	if (!is_reg(reg))
		return ;
	proc = vm->procs.cur;
	proc->carry = (val == 0);
	ft_bzero(&proc->reg[reg], REG_SIZE);
	regcpy(&proc->reg[reg], &val, REG_SIZE);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("loaded value %d in r%d\n", val, reg);
	vm->print == &printw ? ++vm->nbr_inst : 0;
}

/*
**      Takes a register and copies its value at the given address
*/

void		store(t_vm *vm, int reg, int addr)
{
	t_process		*proc;

	if (!is_reg(reg))
		return ;
	proc = vm->procs.cur;
	arena_store(vm, addr, &proc->reg[reg], REG_SIZE);
	vm->print("Player %d \"%s\" ", proc->champ->id, proc->champ->name);
	vm->print("stored value of r%d at address %d\n", reg, addr);
	vm->print == &printw ? ++vm->nbr_inst : 0;
}
