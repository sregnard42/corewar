/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:33:30 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/08 10:09:27 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
​
static int	check_base(char *base)
{
	int i;
	int j;
​
	j = 0;
	if (base == NULL)
		return (-1);
	while (base[j] != '\0')
	{
		i = j + 1;
		while (base[i] != '\0')
		{
			if (base[j] == base[i])
				return (-1);
			i = i + 1;
		}
		j = j + 1;
	}
	if (j == 0 || j == 1)
		return (-1);
	return (j);
}
​
static int	check_nbr_with_base(char *nbr, char *base)
{
	int	i;
	int	j;
	int	tmp;
​
	j = 0;
	while (nbr[j] != '\0')
	{
		i = 0;
		tmp = 0;
		while (base[i] != '\0')
		{
			if (nbr[j] == base[i])
			{
				tmp = 1;
				break ;
			}
			i = i + 1;
		}
		if (tmp == 0)
			return (-1);
		j = j + 1;
	}
	return (0);
}
​
static void	fill_res(int nb, char *base, int len, char *res)
{
	int		i;
	int		j;
	char	tmp;
​
	i = 0;
	while (nb != 0)
	{
		res[i] = base[nb % len];
		nb = nb / len;
		i = i + 1;
	}
	res[i] = '\0';
	i = i - 1;
	j = 0;
	while (i > j)
	{
		tmp = res[i];
		res[i] = res[j];
		res[j] = tmp;
		i = i - 1;
		j = j + 1;
	}
}
​
char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len1;
	int		len2;
	int		res_tmp;
	char	*res;
​
	if (nbr == NULL || base_from == NULL || base_to == NULL)
		return (NULL);
	len1 = check_base(base_from);
	len2 = check_base(base_to);
	if (check_nbr_with_base(nbr, base_from) == -1)
		return (NULL);
	if (len1 == -1 || len2 == -1)
		return (NULL);
	res_tmp = ft_atoi_base(nbr, base_from);
	if ((res = malloc(sizeof(char) * (len1 * len2))) == NULL)
		return (NULL);
	if (res_tmp == 0)
	{
		res[0] = '0';
		res[1] = '\0';
		return (res);
	}
	fill_res(res_tmp, base_to, len2, res);
	return (res);
}
