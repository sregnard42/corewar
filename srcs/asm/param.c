/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrhuang <chrhuang@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:08:23 by chrhuang          #+#    #+#             */
/*   Updated: 2019/11/19 15:25:37 by chrhuang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** which_param() checks the type of the params
*/

char	which_params(char *param)
{
	if (!param || !*param)
		return (0);
	if (*param == 'r')
	{
		ft_printf("%s is a registre\n", param);
		param++;
		if (ft_isnumber(param))
			return (1);
	}
	else if (*param == DIRECT_CHAR)
	{
		param++;
		ft_printf("%s is a direct\n", param);
		if (*param == LABEL_CHAR || ft_isnumber(param))
			return (2);
	}
	else
	{
		ft_printf("%s is an indirect\n", param);
		if (*param == LABEL_CHAR || ft_isnumber(param))
			return (3);
	}
	return (0);
}


/*
** check_param() checks if the param is compatible with the instruction
*/

char	check_param(t_assembler *as, int id_command, char id_param, int nb_param)
{
	int	type;

	type = as->commands[id_command].param[nb_param];
	if (type == 7 || type == id_param)
		return (1);
	else if (id_param == 1)
		return (type == 3 || type == 5 ? 1 : 0);
	else if (id_param == 2)
		return (type == 3 || type == 6 ? 1 : 0);
	else if (id_param == 3)
		return (type == 5 || type == 6 ? 1 : 0);
	return (0);
}

/*
** is_param() checks if the params are compatible with the command given
*/

int		is_param(t_assembler *as, int id_command, char *part, int nb_param, char *ocp)
{
	// EN COURS
	char	id_param;

	id_param = which_params(part);
	ocp[nb_param] = id_param;
	if (check_param(as, id_command, id_param, nb_param) == 1)
		ft_printf("Yes, bon parametre\n");
	else
		ft_printf("Noooooo, mauvais parametre\n");
	if (id_param != 0)
		return (1);
	return (0);
}