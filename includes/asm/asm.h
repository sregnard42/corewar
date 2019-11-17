/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <sregnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/17 16:57:36 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "common.h"
# include "param.h"
# include "label.h"
# include "command.h"

# define	NAME_COMMENT_EXIST	"Name or comment already exist\n"

typedef struct		s_assembler
{
	t_header		*header;
	char			*file_name_s;
	char			*file_name_cor;
	int				source_fd;
	t_labels		*labels;
	t_commands		*commands;
}					t_assembler;

void	init_asm(t_assembler *as);
void	create_cor(t_assembler *as);
void	parsing(t_assembler *as);
void	clean_line(char *line);
void	parse_instruction(t_assembler *as, char *line);
void	parse_header(t_assembler *as, char *line, char **dst);
void	free_asm(void *a);

#endif
