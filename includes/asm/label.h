/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:28:41 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/17 15:12:17 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_H
# define LABEL_H

# include "asm.h"

typedef struct		s_label
{
	char			*label;
	unsigned char	opcode;
	t_params		params;
	struct s_label	*next;
	struct s_label	*prev;
}					t_label;

typedef struct		s_labels
{
	t_label			*first;
	t_label			*cur;
	t_label			*last;
	unsigned int	size;
}					t_labels;

#endif
