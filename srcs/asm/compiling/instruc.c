/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/27 14:05:30 by chrhuang         ###   ########.fr       */
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

// int		write_label()
// {
//
// 	write_big_endian(fd, res, size); //??? comment on gere les labels
// }

void	write_neg_number(int fd, int nb, int size)
{
	int	tmp;
	unsigned char	octets[4];
	unsigned char			max;

	tmp = 0;
	max = 0xff; //111111
	octets[0] = nb >> 24;
	octets[1] = nb >> 16;
	octets[2] = nb >> 8;
	octets[3] = nb >> 0;
	octets[0] = octets[0] ^ max;
	octets[1] = octets[1] ^ max;
	octets[2] = octets[2] ^ max;
	octets[3] = octets[3] ^ max;
	// tmp = (int)octets;
	// ft_printf("last_tmp = %d\n", tmp);
	// exit(0);
	write(fd, octets, size);
}

void	write_direct(t_assembler *as, int fd, char *param, int size)
{
	int		ret;

	param++;
	(void)as;
	if (*param != ':')
	{
		ret = ft_atoi(param);
		write_big_endian(fd, ret, size);
	}
	else
	{
		write_neg_number(fd, 2, size);
		// res = write_label(as, fd, size);
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
				write_direct(as, fd, tmp->param[i], ret);
			else if (tmp->param_type[i] == 3)
				write_indirect(fd, tmp->param[i]);
			i++;
		}
		tmp = tmp->next;
	}
}
