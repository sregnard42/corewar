/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sregnard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:44:20 by sregnard          #+#    #+#             */
/*   Updated: 2019/11/06 14:15:40 by sregnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		print_hex(char *content, int size)
{
	int	i;
	int index;

	index = 0;
	while (index < size)
	{
		i = 0;
		while (i++ < 16 && index < size)
			ft_printf("%02x ", (unsigned char)content[index++]);
		ft_putln();
	}
}

static void		parse_file(t_vm *vm, char *file)
{
	char	content[CHAMP_MAX_SIZE + 1];
	int		fd;
	int		ret;

	(fd = open(file, O_RDONLY)) == -1 ? 
	ft_error(vm, &free_all, "ERROR: file doesn't exist\n") : 0;
	ret = read(fd, content, CHAMP_MAX_SIZE);
	ft_printf("File size : %dB\n", ret);
	ret < 1 ? ft_error(vm, &free_all, "ERROR: empty file\n") : 0;
	content[ret] = '\0';
	ft_putendl("\nText brut :");
	write(1, content, ret);
	ft_putendl("\nText hexdump :");
	print_hex(content, ret);
}

void		parse_args(t_vm *vm, int ac, char **av)
{
	while(ac--)
		parse_file(vm, *av++);
}
