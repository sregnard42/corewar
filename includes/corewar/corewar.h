/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/13 13:46:30 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define USAGE "[-dump nbr_cycles] [[-n number] champion1.cor] ..."
# define FILE_MIN_SIZE 2192
# define COLUMNS 32

# include "common.h"

# include "param.h"
# include "command.h"
# include "label.h"
# include "process.h"
# include "champ.h"

typedef struct			s_vm
{
	int					ac;
	char				**av;
	char				*exe;
	int					dump;
	int					number;
	t_champs			champs;
	unsigned char		arena[MEM_SIZE];
	unsigned int		flags;
	int					cycle;
	int					cycle_to_die;
}						t_vm;

enum					e_flags_vm
{
	VM_DUMP = (1 << 0),
	VM_NUMBER = (1 << 1),
};

/*
**	Free
*/

void					free_all(void *vm);

/*
**	Error
*/

void					error_usage(t_vm *vm);
void					error_open(t_vm *vm, char *file);
void					error_too_small(t_vm *vm);
void					error_prog_size(t_vm *vm);
void					error_magic(t_vm *vm);

/*
**	Parsing
*/

void					parse_args(t_vm *vm);
void					parse_option(t_vm *vm);

/*
**	Arena
*/

void					arena_print(t_vm *vm);
unsigned char			arena_get(t_vm *vm, int index);
void					arena_set(t_vm *vm, int index, unsigned char c);
void					arena_init(t_vm *vm);

/*
**	Champ
*/

void					champs_ids(t_vm *vm);
void 					champs_add(t_vm *vm, t_champs *champs, t_champ *champ);
t_champ					*champ_new(t_vm *vm);
void					champs_free(t_champs *champs);
void					champ_free(t_champ **champ);
void					champ_print(t_champ *champ);
void					champs_print(t_champs *champs);

/*
**	Label
*/

void 					labels_add(t_vm *vm, t_labels *labels, t_label *label);
t_label					*label_new(t_vm *vm);
void					labels_free(t_labels *labels);
void					label_free(t_label **label);

/*
** Command
*/

void 					cmds_add(t_vm *vm, t_commands *cmds, t_command *cmd);
t_command				*cmd_new(t_vm *vm);
void					cmds_free(t_commands *cmds);
void					cmd_free(t_command **cmd);

/*
** Process
*/

void 					procs_add(t_vm *vm, t_processes *procs, t_process *proc);
t_process				*proc_new(t_vm *vm);
void					procs_free(t_processes *procs);
void					proc_free(t_process **proc);

/*
** Parameter
*/

void 					params_add(t_vm *vm, t_params *params, t_param *param);
t_param					*param_new(t_vm *vm);
void					params_free(t_params *params);
void					param_free(t_param **param);

#endif
