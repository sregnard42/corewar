/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:23:33 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 18:21:20 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_error(void *p, void (*f)(void *), char *msg)
{
	msg ? write(2, "ERROR: ", 7) : 0;
	msg ? write(2, msg, ft_strlen(msg)) : 0;
	if (f && p)
		f(p);
	exit(EXIT_FAILURE);
}
