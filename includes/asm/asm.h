/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/16 15:31:18 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "common.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_assembler
{
	t_header	*header;
	char		*file_name_s;
	char		*file_name_cor;
	int			source_fd;
}				t_assembler;

void	init_asm(t_assembler *assembler);
void	create_cor(t_assembler *assembler);
void	parsing(t_assembler *assembler);
void	parse_name_comment(t_assembler *assembler, char *line);

#endif
