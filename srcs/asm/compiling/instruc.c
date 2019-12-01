/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/01 14:41:34 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** write_big_endian() change order of bytes to big endian, depending of size
** only write the 2 first bytes or 4 of them.
*/

void	write_big_endian(t_assembler *as, int nb, int size)
{
	unsigned char octets[4];

	octets[0] = nb >> 24;
	octets[1] = nb >> 16;
	octets[2] = nb >> 8;
	octets[3] = nb >> 0;
	if (size == 2)
	{
		write(as->cor_fd, &octets[2], 1);
		write(as->cor_fd, &octets[3], 1);
	}
	if (size == 4)
		write(as->cor_fd, octets, size);
}

/*
** write_register()
*/

void	write_register(t_assembler *as, char *param)
{
	// char c = 1;
	// ft_printf("%c\n", c + '0');
	int		ret;

	param++;
	ret = ft_atoi(param);
	write(as->cor_fd, &ret, 1);
}

/*
** write_neg_number() change order of bytes in big endian, then reverse all
** bit (ex: if it was 0, become 1) to express negative number.
** add 1 to octets[3] to write another 1 at the begginning. Depending of size
** only write the 2 first bytes or 4 of them.
*/

void	write_neg_number(t_assembler *as, int nb, int size)
{
	unsigned char	octets[4];
	unsigned char			max;

	max = 0xff;
	octets[0] = nb >> 24;
	octets[1] = nb >> 16;
	octets[2] = nb >> 8;
	octets[3] = nb >> 0;
	octets[0] = octets[0] ^ max;
	octets[1] = octets[1] ^ max;
	octets[2] = octets[2] ^ max;
	octets[3] = octets[3] ^ max;
	octets[3] += 1;
	if (size == 2)
	{
		write(as->cor_fd, &octets[2], 1);
		write(as->cor_fd, &octets[3], 1);
	}
	if (size == 4)
		write(as->cor_fd, octets, size);
}

/*
** write_label() goes through the instructions BEHIND our current instruction
** to find the label reffering in the parameter. If finds the label, write the
** parameter in big endian.
** If it doesn't find the label, goes through all instructions starting from
** the BEGINNING to find it, if it does, writes the parameter with negative
** value.
*/

void	write_label(t_assembler *as, t_instruc *now, char *param)
{
	int			res;
	t_instruc	*tmp;

	tmp = now;
	res = 0;
	param++;
	// ft_printf("param(write label) = %s\n", param);
	// ft_printf("now->label = %s\nparam = %s\n", now->label, param);
	while (tmp)
	{
		if (tmp->label && ft_strcmp(tmp->label, param) == 0)
		{
			ft_printf("res = %d\n", res);
			write_big_endian(as, res, now->direct_size);
			return ;
		}
		res += tmp->size;
		tmp = tmp->next;
	}
	tmp = as->instruc;
	res = 0;
	while (tmp)
	{
		if (tmp->label && ft_strcmp(tmp->label, param) == 0)
		{
			while (tmp)
			{
				if (tmp == now)
				{
					ft_printf("neg res = %d\n", res);
					write_neg_number(as, res, now->direct_size);
				}
				res += tmp->size;
				tmp = tmp->next;
			}
			return ;
		}
		tmp = tmp->next;
	}
}

/*
** write_direct() if it's a classic direct, writes it, if it's a label parameter
** we need to calculate its place with write_label()
*/

void	write_direct(t_assembler *as, char *param, t_instruc *now)
{
	int		ret;

	param++;
	if (*param != LABEL_CHAR)
	{
		ret = ft_atoi(param);
		write_big_endian(as, ret, now->direct_size);
	}
	else
		write_label(as, now, param);
}

/*
** write_indirect()
*/

void	write_indirect(t_assembler *as, char *param)
{
	int		ret;

	ret = ft_atoi(param);
	write_big_endian(as, ret, 4);
}

/*
** write_instruc() for all instructions: writes the opcode and the OPC if there
** is one. Then for all parameters, write them depending on their types.
*/

void	write_instruc(t_assembler *as)
{
	t_instruc		*tmp;
	int				i;

	tmp = as->instruc;
	while (tmp)
	{
		i = 0;
		write(as->cor_fd, &tmp->opcode, 1);
		if (tmp->ocp != 0)
			write(as->cor_fd, &tmp->ocp, 1);
		while (i < 3)
		{
			tmp->direct_size = get_param_bytes(tmp->opcode, tmp->param_type[i]);
			if (tmp->param_type[i] == 1)
				write_register(as, tmp->param[i]);
			else if (tmp->param_type[i] == 2)
				write_direct(as, tmp->param[i], tmp);
			else if (tmp->param_type[i] == 3)
				write_indirect(as, tmp->param[i]);
			i++;
		}
		tmp = tmp->next;
	}
}
