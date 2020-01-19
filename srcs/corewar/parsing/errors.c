/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:36:24 by sregnard          #+#    #+#             */
/*   Updated: 2020/01/19 17:06:04 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	error_open(t_vm *vm, char *file)
{
	ft_printf("ERROR: Can't read source file %s\n", file);
	ft_error(vm, &vm_free, NULL);
}

void	error_usage(t_vm *vm)
{
	ft_printf("usage: %s %s", vm->exe, USAGE);
	ft_printf("\n##### OPTIONS #####\n\n");
	ft_printf("%-6s: %s", "-visu", VISU);
	ft_printf("%-6s: %s", "-dump", DUMP);
	ft_printf("%-6s: %s", "-n", NUMBER);
	ft_printf("%-6s: %s", "-v", VERBOSE);
	ft_printf("\t%-6s: %s", "- 0", VERBOSE_0);
	ft_printf("\t%-6s: %s", "- 1", VERBOSE_1);
	ft_printf("\t%-6s: %s", "- 2", VERBOSE_2);
	ft_printf("\t%-6s: %s", "- 4", VERBOSE_4);
	ft_printf("\t%-6s: %s", "- 8", VERBOSE_8);
	ft_error(vm, &vm_free, NULL);
}
