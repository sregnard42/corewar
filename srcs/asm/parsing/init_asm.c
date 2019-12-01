/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:19:30 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/01 13:41:45 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** {X, Y, Z} --> correspond aux 3 params
** 0 = aucun param
** 1 = registre
** 2 = direct
** 4 = indirect
** 3 = 1 ou 2 (registre ou direct)
** 5 = 1 ou 4
** 6 = 2 ou 4
** 7 = 1 ou 2 ou 4
*/

void	init_asm(t_assembler *as)
{
	t_header	*header;

	ft_bzero(as, sizeof(t_assembler));
	if ((header = ft_memalloc(sizeof(t_header))) == NULL)
		ft_error(as, (void *)&free_asm, ERROR_MALLOC);
	header->magic = COREWAR_EXEC_MAGIC;
	as->header = header;
	as->commands[0] = (t_commands){"live", {2, 0, 0}};
	as->commands[1] = (t_commands){"ld", {6, 1, 0}};
	as->commands[2] = (t_commands){"st", {1, 5, 0}};
	as->commands[3] = (t_commands){"add", {1, 1, 1}};
	as->commands[4] = (t_commands){"sub", {1, 1, 1}};
	as->commands[5] = (t_commands){"and", {7, 7, 1}};
	as->commands[6] = (t_commands){"or", {7, 7, 1}};
	as->commands[7] = (t_commands){"xor", {7, 7, 1}};
	as->commands[8] = (t_commands){"zjmp", {2, 0, 0}};
	as->commands[9] = (t_commands){"ldi", {7, 3, 1}};
	as->commands[10] = (t_commands){"sti", {1, 7, 3}};
	as->commands[11] = (t_commands){"fork", {2, 0, 0}};
	as->commands[12] = (t_commands){"lld", {6, 1, 0}};
	as->commands[13] = (t_commands){"lldi", {7, 3, 1}};
	as->commands[14] = (t_commands){"lfork", {2, 0, 0}};
	as->commands[15] = (t_commands){"aff", {1, 0, 0}};
}
