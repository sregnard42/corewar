/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:11:03 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/04 16:45:40 by lgaultie         ###   ########.fr       */
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
	else if (param == 1)
		return (1);
	else if (param == 2)
	{
		if ((opcode >= 9 && opcode <= 12) || (opcode == 14 || opcode == 15))
			return (2);
		return (4);
	}
	else if (param == 3)
		return (2);
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
		prog_size += get_param_bytes(tmp->opcode, tmp->param_type[i]);
	return (prog_size);
}

/*
**	get_prog_size() calculate the nb of bytes of all commands
*/

void				get_prog_size(t_assembler *as)
{
	t_instruc		*tmp;
	unsigned int	prog_size;

	if (!as || !as->header || !as->instruc)
		manage_error(as, &free_asm, as->epure_line, AS_NULL);
	tmp = as->instruc;
	prog_size = 0;
	while (tmp)
	{
		prog_size += 1;
		if (!(tmp->opcode == 1 || tmp->opcode == 9 || tmp->opcode == 12 ||
			tmp->opcode == 15 || tmp->opcode == 16))
			prog_size += 1;
		prog_size += get_params_bytes(tmp);
		tmp = tmp->next;
	}
	as->prog_size = prog_size;
}
