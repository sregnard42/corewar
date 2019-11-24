/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/24 15:27:39 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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
		write(fd, "X", 1); //OCP : poids des parametres sur 1byte
		// write(fd, &ocp, 1); //OCP
		// write(fd, tmp->command, ft_strlen(tmp->command));
		while (i < 4)
		{
			ret = get_param_bytes(tmp->opcode, tmp->param[i]);
			write (fd, "salut" ,ret);
			// write(fd, tmp->param[i], ft_strlen(tmp->param[i]));
			i++;
		}
		tmp = tmp->next;
	}
}
