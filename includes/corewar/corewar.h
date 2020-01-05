/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:35:14 by sregnard          #+#    #+#             */
/*   Updated: 2019/12/09 19:03:50 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "common.h"

# include <ncurses.h>
# include "arg.h"
# include "process.h"
# include "champ.h"

# define USAGE \
"[-visu -dump N -v N] <[[-n number] champion1.cor]> <...>\n"
# define VISU "Enable visualizer\n"
# define DUMP "Dumps memory after N cycles then exits\n"
# define NUMBER "Sets the number of the next player\n"
# define VERBOSE "Verbosity levels, can be added together to enable several\n"
# define VERBOSE_0 "Show only essentials\n"
# define VERBOSE_1 "Show lives (default)\n"
# define VERBOSE_2 "Show cycles\n"
# define VERBOSE_4 "Show operations (Params are NOT litteral ...)\n"
# define VERBOSE_8 "Show deaths\n"
# define VERBOSE_16 "Show PC movements (Except for jumps)\n"

# define FILE_MIN_SIZE 2192
# define DUMP_COLS 32
# define VISU_COLS 32*2

typedef struct			s_vm
{
	int					ac;
	char				**av;
	char				*exe;
	int					dump;
	int					number;
	unsigned int		verbose;
	int					(*print)(const char *format, ...);
	t_champs			champs;
	t_champ				*winner;
	t_processes			procs;
	unsigned int		pc;
	unsigned char		arena[MEM_SIZE];
	unsigned char		colors[MEM_SIZE];
	unsigned char		colors_pc[MEM_SIZE];
	unsigned int		flags;
	int					cycle;
	int					cycle_to_die;
	int					cycle_check;
	int					nbr_live;
	int					checks;
}						t_vm;

enum					e_flags_vm
{
	VM_DUMP = (1 << 0),
	VM_NUMBER = (1 << 1),
	VM_VERBOSE = (1 << 2),
	VM_VISU = (1 << 3),
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
**-----------------------------------------------------------------------------
**						Visu
**-----------------------------------------------------------------------------
*/

void					visu_init(t_vm *vm);
void					wait_input(void);

/*
**-----------------------------------------------------------------------------
**						Free
**-----------------------------------------------------------------------------
*/

void					vm_free(void *vm);
void					champs_free(t_champs *champs);
void					champ_free(t_champ **champ);
void					procs_free(t_processes *procs);
void					proc_free(t_process **proc);
void					args_free(t_args *args);
void					arg_free(t_arg **arg);

/*
**-----------------------------------------------------------------------------
**						Print
**-----------------------------------------------------------------------------
*/

int (*vm_print(t_vm *vm, unsigned int flag))(const char *format, ...);
void					arena_print(t_vm *vm, unsigned int cols);
void					champ_print(t_champ *champ);
void					champs_print(t_champs *champs);

/*
**-----------------------------------------------------------------------------
**						Parsing
**-----------------------------------------------------------------------------
*/

void					parse_args(t_vm *vm);
void					parse_option(t_vm *vm);

/*
**-----------------------------------------------------------------------------
**						Errors
**-----------------------------------------------------------------------------
*/

void					error_usage(t_vm *vm);
void					error_open(t_vm *vm, char *file);
void					error_too_small(t_vm *vm);
void					error_prog_size(t_vm *vm);
void					error_magic(t_vm *vm);

/*
**-----------------------------------------------------------------------------
**						Arena
**-----------------------------------------------------------------------------
*/

unsigned int			arena_id(t_vm *vm, int index);
unsigned char			arena_get(t_vm *vm, int index);
void					arena_set(t_vm *vm, int index, unsigned char c,
						unsigned int id_player);
void					arena_load(t_vm *vm, int index, void *dst, size_t n);
void					arena_store(t_vm *vm, int index, const void *src,
						size_t n, unsigned int id);
void					arena_init(t_vm *vm);
void					fight(t_vm *vm);

/*
**-----------------------------------------------------------------------------
**						Champions
**-----------------------------------------------------------------------------
*/

void					champs_sort(t_vm *vm);
void					champs_ids(t_vm *vm);
void 					champs_add(t_vm *vm, t_champs *champs, t_champ *champ);
void 					champs_del(t_champs *champs, t_champ **champ_ptr);
t_champ					*champ_new(t_vm *vm);

/*
**-----------------------------------------------------------------------------
**						Processes
**-----------------------------------------------------------------------------
*/

void					print_reg(t_vm *vm, t_reg *reg);
int						is_reg(int id);
void					regcpy(void *dst, const void *src, size_t n);
void					proc_set_pc(t_vm *vm, t_process *proc, unsigned int pc);
void					proc_exec(t_vm *vm, t_champ *champ, t_process *proc);
void 					procs_add(t_vm *vm, t_processes *procs,
						t_process *proc);
void 					procs_del(t_vm *vm, t_processes *procs,
						t_process **proc_ptr);
t_process				*proc_new(t_vm *vm);

/*
**-----------------------------------------------------------------------------
** 						Arguments
**-----------------------------------------------------------------------------
*/

void 					args_add(t_vm *vm, t_args *args, t_arg *arg);
t_arg					*arg_new(t_vm *vm);

/*
**-----------------------------------------------------------------------------
** 						Instructions
**-----------------------------------------------------------------------------
*/

void					ocp(t_vm *vm, int opcode);
void					get_param(t_vm *vm, t_arg *arg, int opcode);
int						get_val(t_vm *vm, t_arg *arg, int *val, int modulo);
void					load(t_vm *vm, int reg, int val);
void					store(t_vm *vm, int reg, int addr);

#endif
