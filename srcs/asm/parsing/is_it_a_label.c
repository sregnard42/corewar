/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_it_a_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:41:16 by lgaultie          #+#    #+#             */
/*   Updated: 2020/01/21 18:44:30 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** check_label_chars() must be: "abcdefghijklmnopqrstuvwxyz_0123456789"
*/

static void	check_label_chars(t_assembler *as, char *str)
{
	int	i;
	int	j;
	int	len_j;
	int	len_i;

	i = 0;
	j = 0;
	len_j = ft_strlen(LABEL_CHARS);
	len_i = ft_strlen(str);
	while (i < len_i && j < len_j && str[i] != LABEL_CHARS[j])
	{
		j++;
		if (j == len_j)
			manage_error(as, &free_asm, INVALID_LABEL);
		if (str[i] == LABEL_CHARS[j])
		{
			i++;
			j = 0;
		}
	}
}

/*
** is_label() checks if it's a label /!\ possible d'avoir un label invalide ?
** (ex trop long)
** returns SUCCESS if it's a label, FAIL if it's not, and ERROR for comments
** to ignore.
*/

int			is_label(t_assembler *as, char *part)
{
	char	*ret;
	char	*str;
	char	*label;

	if (part[0] == COMMENT_CHAR || part[0] == ';')
		return (ERROR);
	if ((ret = ft_strchr(part, LABEL_CHAR)) == NULL \
		|| ft_strchr(part, DIRECT_CHAR) != NULL)
		return (FAIL);
	ft_strlen(ret) > 1 ? manage_error(as, &free_asm, SPACE_LABEL) : 0;
	if (!(str = ft_strsub(part, 0, ret - part)))
		manage_error(as, &free_asm, ERROR_MALLOC);
	if (ft_strlen(ret) == 1 && ret[0] == LABEL_CHAR)
	{
		check_label_chars(as, str);
		if (!(label = ft_strsub(str, 0, ft_strchr(part, LABEL_CHAR) - part)))
			manage_error(as, &free_asm, ERROR_MALLOC);
		ft_strlen(label) == 0 ? manage_error(as, &free_asm, EMPTY_LABEL) : 0;
		save_label_to_check(as, label);
		ft_memdel((void**)&label);
		ft_memdel((void**)&str);
		return (SUCCESS);
	}
	ft_memdel((void**)&str);
	return (FAIL);
}

static void	add_label(t_assembler *as)
{
	t_instruc	*tmp;
	t_instruc	*new;

	if (as->newline != 1)
	{
		tmp = as->instruc;
		if (!(new = ft_memalloc(sizeof(t_instruc))))
			manage_error(as, &free_asm, ERROR_MALLOC);
		if (tmp != NULL)
		{
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
		else
			as->instruc = new;
	}
	else
	{
		tmp = as->instruc;
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = tmp;
	}
	save_same_label(as, new, as->line);
}

void		save_label(t_assembler *as)
{
	int			i;

	!ft_strchr(as->line, LABEL_CHAR) ? manage_error(as, &free_asm, JUNK) : 0;
	i = -1;
	while (as->line[++i])
		if (as->line[i] == LABEL_CHAR)
			as->line[i] = '\0';
	add_label(as);
	save_label_to_check(as, as->line);
	as->newline = 1;
	return ;
}
