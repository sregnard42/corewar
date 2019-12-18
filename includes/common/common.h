/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:14:35 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/21 17:51:36 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"
# include "op.h"

# define PADDING 4

# define LIVE 1
# define LD 2
# define ST 3
# define ADD 4
# define SUB 5
# define AND 6
# define OR 7
# define XOR 8
# define ZJMP 9
# define LDI 10
# define STI 11
# define FORK 12
# define LLD 13
# define LLDI 14
# define LFORK 15
# define AFF 16

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

static char	*op_names[17] = { NULL, "live", "ld", "st", "add",
								"sub", "and", "or", "xor",
								"zjmp", "ldi", "sti", "fork",
								"lld", "lldi", "lfork", "aff"};

static void	(*op[17])(void *) = { NULL, &op_live, &op_ld, &op_st, &op_add,
									&op_sub, &op_and, &op_or, &op_xor,
									&op_zjmp, &op_ldi, &op_sti, &op_fork,
									&op_lld, &op_lldi, &op_lfork, &op_aff};

static int	op_cycles[17] = { 0, 10, 5, 5, 10,
								10, 6, 6, 6,
								20, 25, 25, 800,
								10, 50, 1000, 2};

#endif
