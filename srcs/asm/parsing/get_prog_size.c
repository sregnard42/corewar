/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:11:03 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/21 18:45:43 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get_param_bytes() returns the nb of byte(s) of the given parameter
** param = 0 -> error
** param = 1 -> register
** param = 2 -> direct
** param = 3 -> indirect
*/

unsigned int	get_param_bytes(int opcode, char param)
{
	if (param == 0)
		return (0);
	else if (param == REG_CODE)
		return (RID_SIZE);
	else if (param == DIR_CODE)
	{
		if ((opcode >= ZJMP && opcode <= FORK) \
			|| (opcode == LLDI || opcode == LFORK))
			return (IND_SIZE);
		return (DIR_SIZE);
	}
	else if (param == IND_CODE)
		return (IND_SIZE);
	return (0);
}

/*
**	get_params_bytes() calculate the nb of bytes of all parameters of 1 command
*/

unsigned int	get_params_bytes(t_instruc *tmp)
{
	int				i;
	unsigned int	prog_size;

	i = -1;
	prog_size = 0;
	while (++i < 3)
	{
		prog_size += get_param_bytes(tmp->opcode, tmp->param_type[i]);
	}
	return (prog_size);
}

/*
**	get_prog_size() calculate the nb of bytes of all commands
*/

void			get_prog_size(t_assembler *as)
{
	t_instruc		*tmp;
	unsigned int	prog_size;

	if (!as || !as->header || !as->instruc)
		manage_error(as, &free_asm, AS_NULL);
	tmp = as->instruc;
	prog_size = 0;
	while (tmp)
	{
		prog_size += 1;
		if (tmp->opcode)
		{
			if (!(tmp->opcode == LIVE || tmp->opcode == ZJMP	\
				|| tmp->opcode == FORK || tmp->opcode == LFORK))
				prog_size += 1;
		}
		if (!tmp->opcode && !tmp->param_type && tmp->next != NULL)
			manage_error(as, &free_asm, AS_NULL);
		if (tmp->opcode && tmp->param_type)
			prog_size += get_params_bytes(tmp);
		else
			prog_size--;
		tmp = tmp->next;
	}
	as->prog_size = prog_size;
}
