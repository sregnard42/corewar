/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 18:21:45 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_H
# define COMMAND_H

# include "corewar.h"

typedef struct			s_command
{
	char				type;
	char				ocp;
	t_params			*params;
	struct s_command	*next;
}						t_command;

typedef struct			s_commands
{
	t_command			*first;
	t_command			*cur;
	t_command			*last;
	unsigned int		size;
}						t_commands;

#endif
