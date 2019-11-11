/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:14:35 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/11 11:28:18 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# define PADDING 4

# include "libft.h"
# include "op.h"

void		op_live(void *);
void		op_ld(void *);
void		op_st(void *);
void		op_add(void *);
void		op_sub(void *);
void		op_and(void *);
void		op_or(void *);
void		op_xor(void *);
void		op_zjmp(void *);
void		op_ldi(void *);
void		op_sti(void *);
void		op_fork(void *);
void		op_lld(void *);
void		op_lldi(void *);
void		op_lfork(void *);
void		op_aff(void *);

static void (*op[17])(void *) = { NULL, &op_live, &op_ld, &op_st, &op_add,
									&op_sub, &op_and, &op_or, &op_xor,
									&op_zjmp, &op_ldi, &op_sti, &op_fork,
									&op_lld, &op_lldi, &op_lfork, &op_aff};


#endif
