/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:40:13 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/08 10:10:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
​
int	ft_atoi_base(char *nb, char *base)
{
	int	i;
	int	j;
	int	res;
	int	len;
​
	if (nb == NULL || base == NULL)
		return (-1);
	i = 0;
	res = 0;
	len = ft_strlen(base);
	while (nb[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[j] == nb[i])
				break ;
			j = j + 1;
		}
		res = res + j;
		if (nb[i + 1] != '\0')
			res = res * len;
		i = i + 1;
	}
	return (res);
}
