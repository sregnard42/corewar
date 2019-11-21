/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:01:34 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 13:33:09 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# include "corewar.h"

typedef struct			s_arg
{
	unsigned int		val;
	unsigned int		type;
	struct s_arg		*next;
	struct s_champ		*champ;
	struct s_process	*proc;
	struct s_args		*list;
}						t_arg;

typedef struct			s_args
{
	t_arg				*first;
	t_arg				*cur;
	t_arg				*last;
	unsigned int		size;
}						t_args;

#endif
