/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/17 17:08:49 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define USAGE "[-dump nbr_cycles] [[-n number] champion1.cor] ..."
# define FILE_MIN_SIZE 2192
# define COLUMNS 32

# include "common.h"

# include "arg.h"
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
	unsigned char		colors[MEM_SIZE];
	unsigned int		flags;
	int					cycle;
	int					cycle_to_die;
	int					nbr_live;
	int					checks;
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
void					champs_free(t_champs *champs);
void					champ_free(t_champ **champ);
void					procs_free(t_processes *procs);
void					proc_free(t_process **proc);
void					args_free(t_args *args);
void					arg_free(t_arg **arg);

/*
**	Print
*/

void					arena_print(t_vm *vm);
void					champ_print(t_champ *champ);
void					champs_print(t_champs *champs);

/*
**	Parsing
*/

void					parse_args(t_vm *vm);
void					parse_option(t_vm *vm);

/*
**	Errors
*/

void					error_usage(t_vm *vm);
void					error_open(t_vm *vm, char *file);
void					error_too_small(t_vm *vm);
void					error_prog_size(t_vm *vm);
void					error_magic(t_vm *vm);

/*
**	Arena
*/

unsigned char			arena_get(t_vm *vm, int index);
void					arena_set(t_vm *vm, int index, unsigned char c);
void					arena_init(t_vm *vm);
void					fight(t_vm *vm);

/*
**	Champions
*/

void					champs_sort(t_vm *vm);
void					champs_ids(t_vm *vm);
void 					champs_add(t_vm *vm, t_champs *champs, t_champ *champ);
void 					champs_del(t_champs *champs, t_champ **champ_ptr);
t_champ					*champ_new(t_vm *vm);

/*
** Processes
*/

void					proc_set_pc(t_vm *vm, t_process *proc, unsigned int pc);
void					proc_exec(t_vm *vm, t_champ *champ, t_process *proc);
void 					procs_add(t_vm *vm, t_processes *procs, t_process *proc);
void 					procs_del(t_vm *vm, t_processes *procs, t_process **proc_ptr);
t_process				*proc_new(t_vm *vm);

/*
** argeters
*/

void 					args_add(t_vm *vm, t_args *args, t_arg *arg);
t_arg					*arg_new(t_vm *vm);

#endif
