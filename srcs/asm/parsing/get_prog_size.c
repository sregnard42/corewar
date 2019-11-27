/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:11:03 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/27 12:17:59 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get_param_bytes() returns the nb of byte(s) of the given param
** param = 0 -> erreur
** param = 1 -> registre
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

void				get_prog_size(t_assembler *as)
{
	t_instruc		*tmp;
	unsigned int	prog_size;

	if (!as || !as->header || !as->instruc)
		ft_error(as, &free_asm, "get_prog_size => as is NULL\n");
	ft_printf("prog_size = %d\n", as->header->prog_size);
	tmp = as->instruc;
	prog_size = 0;
	while (tmp)
	{
		prog_size += get_params_bytes(tmp);
		tmp = tmp->next;
		ft_putstr("\n");
	}
	as->prog_size = prog_size + 6;	//pour passer en hexa...
	ft_printf("as->prog_size = %d\n", as->prog_size);
	ft_putstr("------------------\n");
}
