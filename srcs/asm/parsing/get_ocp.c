/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ocp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:04:05 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/24 16:52:44 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_ocp(t_instruc *instruc)
{
	unsigned char	ocp;

	if (instruc->opcode == 1 || instruc->opcode == 9 || instruc->opcode == 12 \
		|| instruc->opcode == 15 || instruc->opcode == 16)
	{
		instruc->ocp = 0;
		return ;
	}
	ocp = 0;
	ocp = ocp | instruc->param_type[0] << 6;
	ocp = ocp | instruc->param_type[1] << 4;
	ocp = ocp | instruc->param_type[2] << 2;
	instruc->ocp = ocp;
}
