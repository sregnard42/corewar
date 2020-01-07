/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:44:57 by chrhuang          #+#    #+#             */
/*   Updated: 2020/01/07 16:35:01 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*delete_begin(char *str)
{
	while (str && *str && (*str == ' ' || *str == '\t'))
		++str;
	return (str);
}

void	delete_between(char *str, char *clean)
{
	int		i;

	i = 0;
	while (str && *str)
	{
		if (*str != ' ' && *str != '\t')
			clean[i] = *str;
		else
		{
			clean[i++] = *str++;
			while (*str && (*str == ' ' || *str == '\t'))
				++str;
			continue ;
		}
		++i;
		++str;
	}
	clean[i] = '\0';
}

void	delete_end(char *clean)
{
	int	i;

	i = ft_strlen(clean) - 1;
	while (clean[i] == ' ' || clean[i] == '\t')
		clean[i--] = '\0';
}

char	*ft_strclean(char *str)
{
	char	*clean;

	if (!str)
		return (NULL);
	if ((clean = ft_memalloc(sizeof(char) * ft_strlen(str))) == NULL)
		return (NULL);
	str = delete_begin(str);
	delete_between(str, clean);
	delete_end(clean);
	return (clean);
}
