/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/11 15:51:32 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROCESS_H
# define PROCESS_H

# include "corewar.h"

typedef struct			s_process
{
	int					pc;
	unsigned char		reg[REG_NUMBER + 1][REG_SIZE];
	bool				live;
	bool				carry;
	struct s_process	*next;
}						t_process;

typedef struct			s_processes
{
	t_process			*first;
	t_process			*cur;
	t_process			*last;
	unsigned int		size;
}						t_processes;

#endif
