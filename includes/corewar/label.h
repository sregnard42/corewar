/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/04 15:11:40 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

# include "corewar.h"

typedef struct		s_label
{
	struct s_label	*next;
}					t_label;

typedef struct		s_labels
{
	t_label			*first;
	t_label			*current;
	t_label			*last;
	unsigned int	size;
}					t_labels;

#endif
