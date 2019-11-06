/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 18:12:42 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMP_H
# define CHAMP_H

# include "corewar.h"

typedef struct		s_champ
{
	char			*name;
	char			content[BUFF_SIZE + 1];
	t_labels		*labels;
	t_commands		*cmds;
	t_processes		*procs;
	struct s_champ	*next;
}					t_champ;

typedef struct		s_champs
{
	t_champ			*first;
	t_champ			*current;
	t_champ			*last;
	unsigned int	size;
}					t_champs;

#endif
