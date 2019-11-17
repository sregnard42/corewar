/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instruc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 21:57:13 by lgaultie          #+#    #+#             */
/*   Updated: 2019/11/17 23:23:47 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "asm.h"

int		tab_len(char **tab)
{
	int		i;
		i = 0;
	while (tab[i] != '\0')
		i++;
	return (i);
}

int		is_label(char *part)
{
	char *ret;

	if ((ret = ft_strchr(part, LABEL_CHAR)) == NULL)
		return (0);
	if (ft_strcmp(ret, ":") == 0)
		return (1);
	return (0);
}

int		is_command(char *part)
{
	if (ft_strcmp(part, "live") != 0 && ft_strcmp(part, "ld") != 0 \
	&& ft_strcmp(part, "st") != 0 && ft_strcmp(part, "add") != 0 \
	&& ft_strcmp(part, "sub") != 0 && ft_strcmp(part, "and") != 0 \
	&& ft_strcmp(part, "or") != 0 && ft_strcmp(part, "xor") != 0 \
	&& ft_strcmp(part, "zjmp") != 0 && ft_strcmp(part, "ldi") != 0 \
	&& ft_strcmp(part, "sti") != 0 && ft_strcmp(part, "fork") != 0 \
	&& ft_strcmp(part, "lld") != 0 && ft_strcmp(part, "lldi") != 0 \
	&& ft_strcmp(part, "lfork") != 0 && ft_strcmp(part, "aff") != 0)
		return (0);
	return (1);
}

int		is_param(char *part)
{
	// EN COURS
	// if (ft_strcmp(part, "r1") == 0)
	// return (1);
	(void)part;
	return (0);
}

void	check_instruc(t_assembler *as, char *line)
{
	char	**tab;
	int		len;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		ft_error(as, &free_asm, "Malloc failed\n");
	len = tab_len(tab);
	while (i < len)
	{
		if (is_label(tab[i]) == 1)
			ft_printf("%s is a		label\n", tab[i]);
		else if (is_command(tab[i]) == 1)
			ft_printf("%s is a		command\n", tab[i]);
		else if (is_param(tab[i]) == 1)
			ft_printf("%s is a			param\n", tab[i]);
		else
		{
			ft_printf("%s --> ", tab[i]);
			ft_error(as, &free_asm, "syntax error, element is neither a label nor a command nor a parameter\n");
		}
		i++;
	}
	add_instruct(as, line);
	// //10 elem in array
	//
	// int i;
	// i = 0
	// max = 10;
	// while ((res != 1 || res != -1) && i < max)
	// {
		// 	res = tableau_defonction[i](prarams);
		// 	i++;
		// }

	// EXAMPLE
	// int sum(int num1, int num2);
	// int sub(int num1, int num2);
	// int mult(int num1, int num2);
	// int div(int num1, int num2);
	//
	// int main()
	// {  int x, y, choice, result;
	//   int (*ope[4])(int, int);
	//   ope[0] = sum;
	//   ope[1] = sub;
	//   ope[2] = mult;
	//   ope[3] = div;
	//   printf("Enter two integer numbers: ");
	//   scanf("%d%d", &x, &y);
	//   printf("Enter 0 to sum, 1 to subtract, 2 to multiply, or 3 to divide: ");
	//   scanf("%d", &choice);
	//   result = ope[choice](x, y);
	//   printf("%d", result);
	// return 0;}
	//
	// int sum(int x, int y) {return(x + y);}
	// int sub(int x, int y) {return(x - y);}
	// int mult(int x, int y) {return(x * y);}
	// int div(int x, int y) {if (y != 0) return (x / y); else  return 0;}
}
