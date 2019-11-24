/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/24 16:58:11 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_registre(int fd, char *param)
{
	// char c = 1;
	// ft_printf("%c\n", c + '0');
	int		ret;

	ft_printf("registre = %s\n", param);
	param++;
	ret = ft_atoi(param);
	write(fd, &ret, 1);
}

void	write_direct(int fd, char *param, int size)
{
	int		ret;

	(void)fd;
	(void)param;
	ft_printf("direct = %s\n", param);
	param++;
	if (*param != ':')
	{
		ret = ft_atoi(param);
		write(fd, &ret, size);
	}
	else
	{
		write (fd, "XXXX", size); //??? comment on gere les labels
	}
}

void	write_indirect(int fd, char *param)
{
	int		ret;

	ret = ft_atoi(param);
		write(fd, &ret, 2);
	ft_printf("INDIRECT = %s\n", param);
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
				write_registre(fd, tmp->param[i]);		//sur 1 byte
			else if (tmp->param_type[i] == 2)
				write_direct(fd, tmp->param[i],ret);		//sur 2 bytes
			else if (tmp->param_type[i] == 3)
				write_indirect(fd, tmp->param[i]);		//sur 3 bytes
			i++;
		}
		tmp = tmp->next;
	}
}
