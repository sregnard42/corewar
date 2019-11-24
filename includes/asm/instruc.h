/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:17:15 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/24 15:30:02 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUC_H
# define INSTRUC_H

# include "asm.h"

typedef struct				s_instruc
{
	char					*label;
	char					*command;
	int						opcode;
	char					*param[4];
	char					*param_type;
	// char 					ocp;
	struct s_instruc		*next;
	struct s_instruc		*prev;
}							t_instruc;

#endif
