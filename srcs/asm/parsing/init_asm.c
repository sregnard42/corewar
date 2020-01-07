/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:19:30 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/07 19:28:13 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** {X, Y, Z} -->  X is the first parameter, Y second, Z third parameter
** numbers stands for type of parameter:
** 0 = no parameter
** 1 = register
** 2 = direct
** 4 = indirect
** 3 = 1 or 2 (register or direct)
** 5 = 1 or 4 (register or indirect)
** 6 = 2 or 4 (direct or indirect)
** 7 = 1 or 2 or 4 (all parameters accepted)
** last number is the number of parameters for this command
*/

void	init_asm(t_assembler *as, unsigned int flag)
{
	t_header	*header;

	ft_bzero(as, sizeof(t_assembler));
	if ((header = ft_memalloc(sizeof(t_header))) == NULL)
		manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	header->magic = COREWAR_EXEC_MAGIC;
	as->header = header;
	as->commands[0] = (t_commands){"live", {2, 0, 0}, 1};
	as->commands[1] = (t_commands){"ld", {6, 1, 0}, 2};
	as->commands[2] = (t_commands){"st", {1, 5, 0}, 2};
	as->commands[3] = (t_commands){"add", {1, 1, 1}, 3};
	as->commands[4] = (t_commands){"sub", {1, 1, 1}, 3};
	as->commands[5] = (t_commands){"and", {7, 7, 1}, 3};
	as->commands[6] = (t_commands){"or", {7, 7, 1}, 3};
	as->commands[7] = (t_commands){"xor", {7, 7, 1}, 3};
	as->commands[8] = (t_commands){"zjmp", {2, 0, 0}, 1};
	as->commands[9] = (t_commands){"ldi", {7, 3, 1}, 3};
	as->commands[10] = (t_commands){"sti", {1, 7, 3}, 3};
	as->commands[11] = (t_commands){"fork", {2, 0, 0}, 1};
	as->commands[12] = (t_commands){"lld", {6, 1, 0}, 2};
	as->commands[13] = (t_commands){"lldi", {7, 3, 1}, 3};
	as->commands[14] = (t_commands){"lfork", {2, 0, 0}, 1};
	as->commands[15] = (t_commands){"aff", {1, 0, 0}, 1};
	as->bonus = flag;
	if (as->bonus & BONUS_FOLDER)
	{
		mkdir("my_champs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if (!(as->folder = ft_strdup("./my_champs/")))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
	else
	{
		if (!(as->folder = ft_strdup("./")))
			manage_error(as, &free_asm, as->epure_line, ERROR_MALLOC);
	}
}
