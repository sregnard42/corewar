/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:56:38 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 16:22:24 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** write_direct() if it's a classic direct, writes it, if it's a label parameter
** we need to calculate its place with write_label()
*/

static void		write_direct(t_assembler *as, char *param, t_instruc *now)
{
	int		ret;

	param++;
	if (*param != LABEL_CHAR)
	{
		if (ft_islong(param))
		{
			ret = ft_atoi(param);
			write_big_endian(as, ret, now->direct_size);
		}
		else
		{
			if (*param == '-')
				write_big_endian(as, 0x0, now->direct_size);
			else
				write_big_endian(as, 0xffffffff, now->direct_size);
		}
	}
	else
		write_label(as, now, param);
}

/*
** write_indirect()
*/

static void		write_indirect(t_assembler *as, char *param, t_instruc *now)
{
	int		ret;

	ret = ft_atoi(param);
	if (*param != LABEL_CHAR)
	{
		if (ft_islong(param))
		{
			ret = ft_atoi(param);
			write_big_endian(as, ret, IND_SIZE);
		}
		else
		{
			if (*param == '-')
				write_big_endian(as, 0x0, IND_SIZE);
			else
				write_big_endian(as, 0xffffffff, IND_SIZE);
		}
	}
	else
		write_label(as, now, param);
}

static void		write_params(t_assembler *as, t_instruc *tmp, int i)
{
	if (tmp->opcode && tmp->param_type)
		tmp->direct_size = get_param_bytes(tmp->opcode, tmp->param_type[i]);
	if (tmp->param_type)
	{
		if (tmp->param_type[i] == REG_CODE)
			write_register(as, tmp->param[i]);
		else if (tmp->param_type[i] == DIR_CODE)
			write_direct(as, tmp->param[i], tmp);
		else if (tmp->param_type[i] == IND_CODE)
			write_indirect(as, tmp->param[i], tmp);
	}
}

/*
** write_instruc() for all instructions: writes the opcode and the OPC if there
** is one. Then for all parameters, write them depending on their types.
*/

void			write_instruc(t_assembler *as)
{
	t_instruc		*tmp;
	int				i;

	tmp = as->instruc;
	while (tmp)
	{
		i = 0;
		if (tmp->opcode)
			write(as->cor_fd, &tmp->opcode, 1);
		if (tmp->ocp && tmp->ocp != 0)
			write(as->cor_fd, &tmp->ocp, 1);
		while (i < 3)
		{
			write_params(as, tmp, i);
			i++;
		}
		tmp = tmp->next;
	}
}
