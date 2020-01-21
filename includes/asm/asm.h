/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 17:28:48 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 16:53:16 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <sys/stat.h>
# include "common.h"

# define SUCCESS 1
# define FAIL 0
# define ERROR -1

# define NB_COMMANDS 16

# define SAVE_NAME 1
# define SAVE_COMMENT 2

/*
** GENERAL
*/

# define JUNK	"There is some junk on a line.\n"
# define ERROR_MALLOC	"Error with malloc.\n"
# define CANT_READ		"Can't read source file. Does it exist?\n"
# define AS_NULL		"Structure is null.\n"
# define EMPTY_FILE 	"Empty file.\n"
# define NOT_S_FILE 	"Please give a .s file.\n"
# define WTF_IS_THIS "syntax error, element isn't a label/command/parameter.\n"

/*
** COMMAND
*/

# define TOO_MANY_CMD	"Must be one command per line.\n"
# define CMD_NOT_FOUND	"Command not found.\n"

/*
** LABEL
*/

# define REDEF_LABEL		"Redefinition of label.\n"
# define EMPTY_LABEL		"Label is empty.\n"
# define SPACE_LABEL		"No space after label.\n"
# define INVALID_LABEL		"Label with invalid characters.\n"
# define NO_EXIST_LABEL		"Label in argument doesn't exist.\n"
# define LABEL_ALRDY_EXIST	"This label already exists.\n"

/*
** COMMENT/NAME
*/

# define BEFORE_DOT "There is junk before .name or .comment\n"
# define BAD_FORMAT ".name and .comment must be followed by string in quote \n"
# define EMPTY_NAME "Missing name well formated: .name \"champion's name\" \n"
# define EMPTY_COMMENT "Missing .comment well formated: .comment \"comment\"\n"
# define QUOTES_NOT_CLOSED	"Quotes in header are not closed.\n"
# define NO_QUOTES			"No quotes after .name or .comment.\n"
# define NAME_TOO_LONG		"Program name is too long.\n"
# define COMM_TOO_LONG		"Comment is too long.\n"
# define NAME_COMMENT_EXIST	"Name or comment already exist.\n"
# define STUFF_AFTER		"There is some junk after quotes.\n"

/*
** PARAMS
*/

# define WRONG_REGISTER			"Register must be from 1 to REG_NUMBER.\n"
# define INVALID_PARAM			"Param with invalid syntax.\n"
# define WRONG_COMMAND_PARAM	"Invalid param for this command.\n"
# define TOO_MANY_PARAM			"Too many parameters for this command.\n"
# define WRONG_NB_PARAM			"Wrong number of parameters for this command.\n"
# define SEPARATOR_ERROR		"Input error with separators ','.\n"

typedef struct			s_same_label
{
	char				*name;
	struct s_same_label	*next;
}						t_same_label;

typedef struct			s_instruc
{
	t_same_label		*label;
	unsigned int		size;
	char				*command;
	int					opcode;
	char				*param[4];
	char				*param_type;  // "112" --> premier param = 1 = registre
	//deuxieme param = 1 = registre     //troisieme param = 2 = direct
	int					direct_size;
	char 				ocp;
	struct s_instruc	*next;
}						t_instruc;

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
	int				newline;
	int				nb_line;
	char			*epure_line;
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
	char			*folder;
	t_instruc		*instruc;
}					t_assembler;

enum				e_bonus
{
	BONUS_HELP = (1 << 0),
	BONUS_MANAGE_ERROR = (1 << 1),
	BONUS_FOLDER = (1 << 2),
	BONUS_COLOR = (1 << 3),
};

void				init_asm(t_assembler *as, unsigned int flag);
int					check_header(t_assembler *as);
void				create_cor(t_assembler *as);
void				check_label(t_assembler *as, char *label);
void				read_function(t_assembler *as);
void				clean_line(char *line);
void				write_register(t_assembler *as, char *param);
void				write_neg_number(t_assembler *as, int nb, int size);
void				write_big_endian(t_assembler *as, int nb, int size);
void				analyse_instruction(t_assembler *as);
void				free_asm(void *a);
void				write_label(t_assembler *as, t_instruc *now, char *param);
void				add_instruct(t_assembler *as, char *ocp,
						int id_command);
int					is_param(t_assembler *as, int id_command, char *part,
						int nb_param, char *ocp);
void				save_label_to_check(t_assembler *as, char *param);
void				save_label_param(t_assembler *as, char *param);
void				check_existing_labels(t_assembler *as);
void				write_header(t_assembler *as);
void				get_prog_size(t_assembler *as);
unsigned int		get_params_bytes(t_instruc *tmp);
void				write_magic(int fd, int magic_number);
unsigned int		get_param_bytes(int opcode, char param);
void				write_instruc(t_assembler *as);
void				get_ocp(t_instruc *instruc);
void				manage_error(void *p, void (*f)(void *), char *line,
						char *msg);
void				init_bonus(unsigned int *flag, char **av);
void				print_usage();
void				print_help();
void				print_advices(t_assembler *as);
void				print_file_name(t_assembler *as);
int					which_command(t_assembler *as, char *part);
void				save_same_label(t_assembler *as, t_instruc *new, char *name);
/*
** print functions
*/

void				print_instruc(t_assembler *as);
void				print_labels(t_assembler *as);
void				print_param_labels(t_assembler *as);

#endif
