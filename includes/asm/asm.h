/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <sregnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:15:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/08 15:22:15 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "common.h"
#include <unistd.h>
#include <fcntl.h>

void	parse_name_comment(int fd, char *line);

#endif
