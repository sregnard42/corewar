/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:19:30 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/19 12:49:07 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_asm(t_assembler *as)
{
	t_header	*header;

	ft_bzero(as, sizeof(t_assembler));
	if ((header = ft_memalloc(sizeof(t_header))) == NULL)
		ft_error(as, (void *)&free_asm, "Error with malloc\n");
	header->magic = COREWAR_EXEC_MAGIC;
	as->header = header;
	as->commands[0] = "live";
	as->commands[1] = "ld";
	as->commands[2] = "st";
	as->commands[3] = "add";
	as->commands[4] = "sub";
	as->commands[5] = "and";
	as->commands[6] = "or";
	as->commands[7] = "xor";
	as->commands[8] = "zjmp";
	as->commands[9] = "ldi";
	as->commands[10] = "sti";
	as->commands[11] = "fork";
	as->commands[12] = "lld";
	as->commands[13] = "lldi";
	as->commands[14] = "lfork";
	as->commands[15] = "add";
}
