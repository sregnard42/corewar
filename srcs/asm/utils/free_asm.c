/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:26:47 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/17 11:59:08 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "asm.h"

void	free_header(t_header *header)
{
	if (!header)
		return ;
	header->name ? ft_memdel((void **)&header->name) : 0;
	header->comment ? ft_memdel((void **)&header->comment) : 0;
	ft_memdel((void **)&header);
}

void	free_asm(void *assembler)
{
	t_assembler *my_asm;

	my_asm = (t_assembler *)assembler;
	if (!my_asm)
		return ;
	my_asm->header ? free_header(my_asm->header) : 0;
	my_asm->file_name_s ? ft_memdel((void **)&my_asm->file_name_s) : 0;
	my_asm->file_name_cor ? ft_memdel((void **)&my_asm->file_name_cor) : 0;
}
