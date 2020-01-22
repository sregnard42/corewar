/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islong.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:03:56 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/21 16:19:12 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_islong(char *s)
{
	int					sign;
	unsigned long long	nb;

	if (!s || !ft_isnumber(s))
		return (0);
	nb = 0;
	while (ft_isspace(*s))
		++s;
	sign = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? ++s : 0;
	while (*s == '0')
		++s;
	if (ft_strlen(s) > 19)
		return (0);
	while (ft_isdigit(*s) && nb < LONG_MAX)
		nb = (nb * 10) + *s++ - '0';
	return (sign == 1 ? nb <= LONG_MAX : nb <= (unsigned long)(LONG_MAX + 1));
}
