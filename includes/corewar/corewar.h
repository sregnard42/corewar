/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 12:25:21 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "common.h"

# include "param.h"
# include "command.h"
# include "label.h"
# include "process.h"
# include "champ.h"

typedef struct	s_vm
{
	t_champs			*champs;
	unsigned char		arena[MEM_SIZE];
}				t_vm;

/*
**	Free
*/

void			free_all(void *vm);

/*
**	Arena
*/

void			arena_print(t_vm *vm);
unsigned char	arena_get(t_vm *vm, int index);
void			arena_set(t_vm *vm, int index, unsigned char c);

/*
**	Champ
*/

void 			champs_add(t_vm *vm, t_champs *champs, t_champ *champ);
t_champ			*champ_new(t_vm *vm);
void			champs_free(t_champs **champs_ptr);
void			champ_free(t_champ **champ);

/*
**	Label
*/

void 			labels_add(t_vm *vm, t_labels *labels, t_label *label);
t_label			*label_new(t_vm *vm, t_command *cmd);
void			labels_free(t_labels **labels_ptr);
void			label_free(t_label **label);

/*
** Command
*/

void 			cmds_add(t_vm *vm, t_commands *cmds, t_command *cmd);
t_command		*cmd_new(t_vm *vm);
void			cmds_free(t_commands **cmds_ptr);
void			cmd_free(t_command **cmd);

/*
** Process
*/

void 			procs_add(t_vm *vm, t_processes *procs, t_process *proc);
t_process		*proc_new(t_vm *vm);
void			procs_free(t_processes **procs_ptr);
void			proc_free(t_process **proc);

#endif
