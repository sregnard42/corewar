/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 14:46:37 by chrhuang          #+#    #+#             */
/*   Updated: 2019/12/06 17:06:00 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** s_to_cor() creates the name of .cor file from .s file
*/

char	*s_to_cor(t_assembler *as, char *s)
{
	int		len;
	char	*cor;

	len = ft_strlen(s);
	if ((cor = ft_memalloc(sizeof(char) * (len + 4))) == NULL)
	{
		ft_memdel((void **)&cor);
		manage_error(as, &free_asm,as->epure_line, ERROR_MALLOC);
	}
	ft_strncat(cor, s, len - 1);
	ft_strcat(cor, "cor");
	cor[len + 2] = '\0';
	return (cor);
}

/*
** create_cor() get name of future .cor file, then get fd of .cor file while
** creating it. Calls function to write in it.
*/

void	create_cor(t_assembler *as)
{
	if (as->bonus & BONUS_DONT_QUIT)
	{
		if (as->bonus & BONUS_GOT_ERROR)
		{
			if (as->bonus & BONUS_COLOR)
				ft_putstr("\e[1;31m");
			ft_putstr("\n.cor not created because of error(s).\e[0m\n");
			return ;
		}
	}
	if (as->bonus & BONUS_COLOR)
		ft_putstr("\e[1;31m");
	ft_putstr("Created .cor.\e[0m\n");
	as->file_name_cor = s_to_cor(as, as->file_name_s);
	as->cor_fd = open(as->file_name_cor, O_RDWR | O_CREAT, 0644);
	write_header(as);
	write_instruc(as);
	return ;
}
