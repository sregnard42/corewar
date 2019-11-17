/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmouele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 10:01:00 by cmouele           #+#    #+#             */
/*   Updated: 2019/11/17 10:01:14 by cmouele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**			Frees a command
*/

void		cmd_free(t_command **cmd)
{
    params_free(&(*cmd)->params);
    ft_memdel((void **)cmd);
}

/*
**			Frees all commands in the list then the list itself
*/

void		cmds_free(t_commands *cmds)
{
    while (cmds->first)
    {
        cmds->cur = cmds->first->next;
        cmd_free(&cmds->first);
        cmds->first = cmds->cur;
    }
}
