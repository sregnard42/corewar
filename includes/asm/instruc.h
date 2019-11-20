/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:17:15 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/19 15:30:45 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUC_H
# define INSTRUC_H

# include "asm.h"

typedef struct				s_instruc
{
	char					*label;
	char					*command;
	char					*param[4];
	char					*ocp;
	struct s_instruc		*next;
	struct s_instruc		*prev;
}							t_instruc;

#endif
