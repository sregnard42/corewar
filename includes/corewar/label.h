/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/17 11:42:29 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

# include "corewar.h"

typedef struct		s_label
{
	struct s_label	*prev;
	struct s_label	*next;
	struct s_labels *list;
	struct s_champ	*champ;
}					t_label;

typedef struct		s_labels
{
	t_label			*first;
	t_label			*cur;
	t_label			*last;
	unsigned int	size;
}					t_labels;

#endif
