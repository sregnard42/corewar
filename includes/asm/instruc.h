/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:17:15 by lgaultie          #+#    #+#             */
/*   Updated: 2019/12/04 12:59:40 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUC_H
# define INSTRUC_H

# include "asm.h"

typedef struct			s_instruc
{
	char				*label;
	unsigned int		size;
	char				*command;
	int					opcode;
	char				*param[4];
	char				*param_type;  // "112" --> premier param = 1 = registre
	//deuxieme param = 1 = registre     //troisieme param = 2 = direct
	int					direct_size;
	char 				ocp;
	struct s_instruc	*next;
}						t_instruc;

#endif
