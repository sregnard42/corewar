/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:28:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/19 14:32:06 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "common.h"
# include "instruc.h"

# define	NAME_COMMENT_EXIST	"Name or comment already exist\n"
# define	ERROR_MALLOC		"Error with malloc\n"

typedef	struct		s_commands
{
	char			*command;
	int				param[3];
}					t_commands;


typedef struct		s_assembler
{
	t_header		*header;
	char			*file_name_s;
	t_commands		commands[16];
	char			*file_name_cor;
	int				source_fd;
	t_instruc		*instruc;
}					t_assembler;

void	init_asm(t_assembler *as);
void	create_cor(t_assembler *as);
void	parsing(t_assembler *as);
void	clean_line(char *line);
void	parse_instruction(t_assembler *as, char *line);
void	free_asm(void *a);
void	check_instruc(t_assembler *as, char *line);
void	add_instruct(t_assembler *as, char *line);
////////////////////fonctions de print -- pour debug
void	print_instruc(t_assembler *as);

#endif
