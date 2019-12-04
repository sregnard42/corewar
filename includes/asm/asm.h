/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:28:48 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/04 14:15:13 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "common.h"
# include "instruc.h"

# define	SUCCESS 1
# define	FAIL 0
# define	ERROR -1

# define	NB_COMMANDS 16

// GENERAL

# define	ERROR_MALLOC		"Error with malloc.\n"
# define	CANT_READ			"Can't read source file ds.\n"
# define	AS_NULL				"Structure is null.\n"
# define	EMPTY_FILE			"Empty file.\n"
# define	NOT_S_FILE			"Please give a .s file.\n"
# define	WTF_IS_THIS			"syntax error, element is neither a label nor \
								a command nor a parameter.\n"
// COMMAND

# define	TOO_MANY_CMD		"Must be one command per line.\n"
# define	CMD_NOT_FOUND		"Command not found.\n"

// LABEL

# define	EMPTY_LABEL			"Label is empty.\n"
# define	SPACE_LABEL			"No space after label.\n"
# define	INVALID_LABEL		"Label with invalid characters.\n"
# define	NO_EXIST_LABEL		"Label in argument doesn't exist.\n"
# define	LABEL_ALRDY_EXIST	"This label already exists.\n"

//COMMENT/NAME

# define	EMPTY_NAME			"Missing .name with its string parameter.\n"
# define	EMPTY_COMMENT		"Missing .comment with its string parameter.\n"
# define	QUOTES_NOT_CLOSED	"Quotes in header are not closed.\n"
# define	NO_QUOTES			"No quotes after .name or .comment.\n"
# define	NAME_TOO_LONG		"Program name is too long.\n"
# define	COMM_TOO_LONG		"Comment is too long.\n"
# define	NAME_COMMENT_EXIST	"Name or comment already exist.\n"
# define	STUFF_AFTER			"There is some junk after quotes.\n"

//PARAMS

# define	WRONG_REGISTER		"Register must be from 1 to REG_NUMBER.\n"
# define	INVALID_PARAM		"Param with invalid syntax.\n"
# define	WRONG_COMMAND_PARAM	"Invalid param for this command.\n"
# define	TOO_MANY_PARAM		"Too many parameters for this command.\n"
# define	WRONG_NB_PARAM		"Too few parameters for this command.\n"
# define	SEPARATOR_ERROR		"Input error with separators ','.\n"

typedef	struct		s_commands
{
	char			*command;
	int				param[3];
	int				nb_params;
}					t_commands;

typedef struct		s_label
{
	char			*name;
	struct s_label	*next;
}					t_label;

typedef struct		s_assembler
{
	t_header		*header;
	char			*line;
	char			*file_name_s;
	char			*file_name_cor;
	t_commands		commands[NB_COMMANDS];
	unsigned int	prog_size;
	int				nb_sep;
	t_label			*labels;
	t_label			*param_labels;
	int				s_fd;
	int				cor_fd;
	unsigned int	bonus;
	t_instruc		*instruc;
}					t_assembler;

enum				e_bonus
{
	BONUS_MANAGE_ERROR = (1 << 0),
};

void				init_asm(t_assembler *as);
int					check_header(t_assembler *as);
void				create_cor(t_assembler *as);
void				check_label(t_assembler *as, char *label);
void				parsing(t_assembler *as);
void				clean_line(char *line);
void				parse_instruction(t_assembler *as);
void				free_asm(void *a);
void				add_instruct(t_assembler *as, char *ocp,
						int id_command);
void				is_param(t_assembler *as, int id_command, char *part,
						int nb_param, char *ocp);
void				save_label_to_check(t_assembler *as, char *param);
void				save_label_param(t_assembler *as, char *param);
int					check_existing_labels(t_assembler *as);
void				write_header(t_assembler *as);
void				get_prog_size(t_assembler *as);
unsigned int		get_params_bytes(t_instruc *tmp);
void				write_magic(int fd, int magic_number);
unsigned int		get_param_bytes(int opcode, char param);
void				write_instruc(t_assembler *as);
void				get_ocp(t_instruc *instruc);
void manage_error(void *p, void (*f)(void *), char *line, char *msg);
////////////////////fonctions de print -- pour debug
void	print_instruc(t_assembler *as);
void	print_labels(t_assembler *as);
void	print_param_labels(t_assembler *as);

#endif
