/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/11 15:44:27 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define HELP_FILE "help.txt"
# define FILE_MIN_SIZE 2192

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
	unsigned int		verbose;
	t_champs			*champs;
	unsigned char		arena[MEM_SIZE];
	unsigned int		flags;
	int					cycle;
	int					cycle_to_die;
}						t_vm;

enum					e_flags_vm
{
	VM_A = (1 << 0),
	VM_D = (1 << 1),
	VM_S = (1 << 2),
	VM_V = (1 << 3),
	VM_B = (1 << 4),
	VM_N = (1 << 5),
	VM_STEALTH = (1 << 6),
};

enum					e_flags_verbose
{
	V_LIVES = (1 << 0),
	V_CYCLES = (1 << 1),
	V_OPERATIONS = (1 << 2),
	V_DEATHS = (1 << 3),
	V_MOVES = (1 << 4),
};

/*
**	Free
*/

void					free_all(void *vm);

/*
**	Error
*/

void					error_usage(t_vm *vm);
void					error_too_small(t_vm *vm);
void					error_prog_size(t_vm *vm);
void					error_magic(t_vm *vm);

/*
**	Parsing
*/

void					parse_args(t_vm *vm);
void					parse_option(t_vm *vm);
void					parse_header(t_vm *vm);

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

void 					champs_add(t_vm *vm, t_champs *champs, t_champ *champ);
t_champ					*champ_new(t_vm *vm);
void					champs_free(t_champs **champs_ptr);
void					champ_free(t_champ **champ);
void					champ_print(t_champ *champ);

/*
**	Label
*/

void 					labels_add(t_vm *vm, t_labels *labels, t_label *label);
t_label					*label_new(t_vm *vm);
void					labels_free(t_labels **labels_ptr);
void					label_free(t_label **label);

/*
** Command
*/

void 					cmds_add(t_vm *vm, t_commands *cmds, t_command *cmd);
t_command				*cmd_new(t_vm *vm);
void					cmds_free(t_commands **cmds_ptr);
void					cmd_free(t_command **cmd);

/*
** Process
*/

void 					procs_add(t_vm *vm, t_processes *procs, t_process *proc);
t_process				*proc_new(t_vm *vm);
void					procs_free(t_processes **procs_ptr);
void					proc_free(t_process **proc);

/*
** Parameter
*/

void 					params_add(t_vm *vm, t_params *params, t_param *param);
t_param					*param_new(t_vm *vm);
void					params_free(t_params **params_ptr);
void					param_free(t_param **param);

#endif
