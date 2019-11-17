/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:02:25 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 11:03:26 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**			Frees a parameter
*/

void		param_free(t_param **param)
{
    ft_memdel((void **)param);
}

/*
**			Frees all parameters in the list then the list itself
*/

void		params_free(t_params *params)
{
    while (params->first)
    {
        params->cur = params->first->next;
        param_free(&params->first);
        params->first = params->cur;
    }
}
