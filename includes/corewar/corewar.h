/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/03 15:48:44 by sregnard         ###   ########.fr       */
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
	t_champs	*champs;
}				t_vm;

/*
**	Free
*/

void			free_all(void *vm);

/*
**	Champ
*/

void 			champs_add(t_vm *vm, t_champs *champs, t_champ *champ);
t_champ			*champ_new(t_vm *vm);

/*
**	Label
*/

void 			labels_add(t_vm *vm, t_labels *labels, t_label *label);
t_label			*label_new(t_vm *vm, t_command *cmd);

#endif
