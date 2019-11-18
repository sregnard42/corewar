/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:19:30 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/18 17:12:40 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	**init_commands(t_assembler *as)
{
	char		**commands;

	if ((commands = ft_memalloc(sizeof(char *) * 17)) == NULL)
		ft_error(as, &free_asm, ERROR_MALLOC);
	commands[0] = ft_strdup("live");
	commands[1] = ft_strdup("ld");
	commands[2] = ft_strdup("st");
	commands[3] = ft_strdup("add");
	commands[4] = ft_strdup("sub");
	commands[5] = ft_strdup("and");
	commands[6] = ft_strdup("or");
	commands[7] = ft_strdup("xor");
	commands[8] = ft_strdup("zjmp");
	commands[9] = ft_strdup("ldi");
	commands[10] = ft_strdup("sti");
	commands[11] = ft_strdup("fork");
	commands[12] = ft_strdup("lld");
	commands[13] = ft_strdup("lldi");
	commands[14] = ft_strdup("lfork");
	commands[15] = ft_strdup("aff");
	commands[16] = NULL;
	return (commands);
}

void	init_asm(t_assembler *as)
{
	t_header	*header;

	ft_bzero(as, sizeof(t_assembler));
	if ((header = ft_memalloc(sizeof(t_header))) == NULL)
		ft_error(as, (void *)&free_asm, "Error with malloc\n");
	header->magic = COREWAR_EXEC_MAGIC;
	as->header = header;
	as->commands = init_commands(as);
}
