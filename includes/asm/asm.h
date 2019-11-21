/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:28:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/21 16:51:46 by lgaultie         ###   ########.fr       */
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

typedef struct		s_label
{
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_assembler
{
	t_header		*header;
	char			*file_name_s;
	t_commands		commands[16];
	t_label			*labels;
	t_label			*param_labels;
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
void	add_instruct(t_assembler *as, char *line, char *ocp);
int		is_param(t_assembler *as, int id_command, char *part, int nb_param, char *ocp);
void	save_label_to_check(t_assembler *as, char *param);
void	save_label_param(t_assembler *as, char *param);
int		check_existing_labels(t_assembler *as);
////////////////////fonctions de print -- pour debug
void	print_instruc(t_assembler *as);
void	print_labels(t_assembler *as);
void	print_param_labels(t_assembler *as);

#endif
