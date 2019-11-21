/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 17:42:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "corewar.h"

typedef struct			s_process
{
	int					pc;
	int					cycle;
	unsigned char		reg[REG_NUMBER + 1][REG_SIZE];
	bool				live;
	bool				carry;
	t_args				args;
	struct s_process	*prev;
	struct s_process	*next;
	struct s_processes	*list;
	struct s_champ		*champ;
}						t_process;

typedef struct			s_processes
{
	t_process			*first;
	t_process			*cur;
	t_process			*last;
	unsigned int		size;
}						t_processes;

#endif
