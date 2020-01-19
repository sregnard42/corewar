/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:01:34 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 16:12:04 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# include "corewar.h"

typedef struct			s_arg
{
	int					val;
	unsigned int		type;
	unsigned int		size;
	struct s_arg		*next;
	struct s_champ		*champ;
	struct s_process	*proc;
	struct s_args		*list;
}						t_arg;

typedef struct			s_args
{
	t_arg				*by_id[MAX_ARGS_NUMBER];
	t_arg				*first;
	t_arg				*cur;
	t_arg				*last;
	unsigned int		size;
}						t_args;

#endif
