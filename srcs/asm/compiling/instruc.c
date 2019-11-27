/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/27 14:00:40 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_big_endian(int fd, int nb, int size)
{
	unsigned char octets[4];

	octets[0] = nb >> 24;
	octets[1] = nb >> 16;
	octets[2] = nb >> 8;
	octets[3] = nb >> 0;
	if (size == 2)
	{
		write(fd, &octets[2], 1);
		write(fd, &octets[3], 1);
	}
	if (size == 4)
		write(fd, octets, size);
}

void	write_registre(int fd, char *param)
{
	// char c = 1;
	// ft_printf("%c\n", c + '0');
	int		ret;

	param++;
	ret = ft_atoi(param);
	write(fd, &ret, 1);
}

void	write_label(int fd, int size, t_instruc *start, char *param)
{

	int			res;
	t_instruc	*now;

	now = start;
	res = 0;
	param++;
	// ft_printf("param(write label) = %s\n", param);   //live en params
	// ft_printf("now->label = %s\nparam = %s\n", now->label, param);  //on est sur la ligne 5 et 10
	while (now)
	{
		if (now->label && ft_strcmp(now->label, param) == 0)
		{
			ft_printf("res = %d\n", res);
			write_big_endian(fd, res, size);
			return ;
		}
		res += now->size;
		now = now->next;
	}
	write_big_endian(fd, res, size);
}

void	write_direct(int fd, char *param, int size, t_instruc *now)
{
	int		ret;

	param++;
	// ft_printf("param = %s\n", param);
	if (*param != ':')
	{
		ret = ft_atoi(param);
		write_big_endian(fd, ret, size);
	}
	else
	{
		write_label(fd, size, now, param);
		// write_big_endian(fd, res, size); //??? comment on gere les labels
	}
}

void	write_indirect(int fd, char *param)
{
	int		ret;

	ret = ft_atoi(param);
	write_big_endian(fd, ret, 2);
}

void	write_instruc(t_assembler *as, int fd)
{
	t_instruc		*tmp;
	int				i;
	int				ret;

	tmp = as->instruc;
	while (tmp)
	{
		i = 0;
		write(fd, &tmp->opcode, 1); //OPCODE : id de la commande sur 1byte
		if (tmp->ocp != 0)
			write(fd, &tmp->ocp, 1); //OCP : poids des parametres sur 1byte
		while (i < 3)
		{
			ret = get_param_bytes(tmp->opcode, tmp->param_type[i]);
			if (tmp->param_type[i] == 1)
				write_registre(fd, tmp->param[i]);
			else if (tmp->param_type[i] == 2)
				write_direct(fd, tmp->param[i], ret, tmp);
			else if (tmp->param_type[i] == 3)
				write_indirect(fd, tmp->param[i]);
			i++;
		}
		tmp = tmp->next;
	}
}
