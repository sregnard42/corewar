/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:04:05 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/01 13:49:44 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** get_ocp() if commands haven't ocp, return ocp = 0
** param_type[0] = type du param 1
** param_type[1] = type du param 2
** param_type[2] = type du param 3
** If param type is a reg then param_type = 1 so in binary = 0b01
** param type is a direct then param_type = 2 so in binary = 0b10
** param type is a direct then param_type = 3 so in binary = 0b11
** check param type and put two bit in ocp
**
*/

void	get_ocp(t_instruc *command)
{
	unsigned char	ocp;

	if (command->opcode == 1 || command->opcode == 9 || command->opcode == 12 \
		|| command->opcode == 15 || command->opcode == 16)
	{ // Remplacer les 1 9 12 par les alias qui sont dans le dossier common
		command->ocp = 0;
		return ;
	}
	ocp = 0;
	ocp = ocp | command->param_type[0] << 6;
	ocp = ocp | command->param_type[1] << 4;
	ocp = ocp | command->param_type[2] << 2;
	command->ocp = ocp;
}
