/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:24 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/24 14:58:18 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_instruc(t_assembler *as, int fd)
{
	t_instruc	*tmp;
	int			i;
	char		octet[1];

	tmp = as->instruc;
	while (tmp)
	{
		i = 0;
		octet[0] = tmp->opcode;
		write(fd, octet, 1); //OPCODE
		write(fd, "XXXX", 4); //OCP
		// write(fd, tmp->command, ft_strlen(tmp->command));
		while (i < 3)
		{
			write(fd, tmp->param[i], ft_strlen(tmp->param[i]));
			i++;
		}
		tmp = tmp->next;
	}
}
