/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/27 14:21:28 by chrhuang         ###   ########.fr       */
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


void	write_neg_number(int fd, int nb, int size)
{
	int	tmp;
	unsigned char	octets[4];
	unsigned char			max;

	tmp = 0;
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
		write(fd, &octets[2], 1);
		write(fd, &octets[3], 1);
	}
	if (size == 4)
		write(fd, octets, size);
}

void	write_label(t_assembler *as, int fd, int size, t_instruc *start, char *param)
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
	now = as->instruc;
	res = 0;
	while (now)
	{
		if (now->label && ft_strcmp(now->label, param) == 0)
		{
			while (now)
			{
				if (now == start)
				{
					ft_printf("neg res = %d\n", res);
					write_neg_number(fd, res, size);
				}
				res += now->size;
				now = now->next;
			}
			return ;
		}
		now = now->next;
	}
	// write_big_endian(fd, res, size);
}


// void	write_direct(t_assembler *as, int fd, char *param, int size)

void	write_direct(t_assembler *as, int fd, char *param, int size, t_instruc *now)
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
		// write_neg_number(fd, 2, size);
		// res = write_label(as, fd, size);
		write_label(as, fd, size, now, param);
		// write_big_endian(fd, res, size); //??? comment on gere les labels
	}
}

void	write_indirect(int fd, char *param)
{
	int		ret;

	ret = ft_atoi(param);
	write_big_endian(fd, ret, 4);
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
				write_direct(as, fd, tmp->param[i], ret, tmp);
			else if (tmp->param_type[i] == 3)
				write_indirect(fd, tmp->param[i]);
			i++;
		}
		tmp = tmp->next;
	}
}
