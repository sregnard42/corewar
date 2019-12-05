/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champ.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 18:27:59 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAMP_H
# define CHAMP_H

# include "corewar.h"

typedef struct		s_champ
{
	char			*file;
	char			content[BUFF_SIZE + 1];
	int				size;
	int				cursor;
	unsigned int	magic;
	char			name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
	unsigned int	id;
	unsigned int	pos;
	unsigned int	last_alive;
	unsigned int	lives;
	struct s_champ	*prev;
	struct s_champ	*next;
	struct s_champs	*list;
}					t_champ;

typedef struct		s_champs
{
	t_champ			*byId[MAX_PLAYERS + 1];
	t_champ			*first;
	t_champ			*cur;
	t_champ			*last;
	unsigned int	size;
	unsigned int	sum_procs;
}					t_champs;

#endif
