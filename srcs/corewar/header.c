/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 11:50:40 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/10 13:00:07 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	parse_header(t_vm *vm)
{
	t_champ	*champ;

	champ = vm->champs->cur;
	ft_printf("parse_header\n");
//	for (int i = 0; i < 4; i++)i
//		champ->header.magic += (unsigned char)champ->content[i];
	ft_memcpy(&champ->header.magic, champ->content, 4);
	ft_printf("%#010x\n", champ->header.magic);
	ft_memrev(&champ->header.magic, sizeof(int));
	ft_printf("%#010x\n", champ->header.magic);
	ft_printf("%#010x\n", COREWAR_EXEC_MAGIC);
	ft_printf("%d\n", champ->header.magic);
	ft_printf("%d\n", COREWAR_EXEC_MAGIC);
}
