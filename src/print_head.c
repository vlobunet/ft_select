/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:55:48 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/27 14:55:49 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	print_help(int size)
{
	int			i;
	int			tmp;
	static char	*str[7] = {"[+] : In fd; ", "[-] : Out fd; ",\
		"[sp] : Select; ", "[ctrl+a] : All; ", "[ctrl+x] : None; ",\
		"[\\n] : Verify; ", "[\\b]: Remove;"};

	i = 0;
	while (i < 7 && (int)ft_strlen(str[i]) < size - 4)
	{
		ft_putstr_fd("║ ", 0);
		tmp = 4;
		while (i < 7 && (tmp + (int)ft_strlen(str[i])) < size)
		{
			ft_putstr_fd(str[i], 0);
			tmp = tmp + ft_strlen(str[i++]);
		}
		if (tmp < size)
			while (tmp++ < size)
				ft_putstr_fd(" ", 0);
		ft_putstr_fd(" ║\n", 0);
	}
}

void	print_head(int size)
{
	int		i;
	char	*cwd;

	i = -1;
	ft_putstr_fd(C_MENU, 0);
	ft_putstr_fd("╔", 0);
	while (++i != size - 2)
		ft_putstr_fd("═", 0);
	ft_putstr_fd("╗", 0);
	i = -1;
	print_help(size);
	ft_putstr_fd("╚", 0);
	while (++i != size - 2)
		ft_putstr_fd("═", 0);
	ft_putstr_fd("╝", 0);
	ft_putstr_fd(C_RESET, 0);
	cwd = getcwd(NULL, 4096);
	if ((int)ft_strlen(cwd) + 4 < size)
	{
		ft_putstr_fd("  \033[03;38;05;242m", 0);
		ft_putendl_fd(cwd, 0);
		ft_putstr_fd(C_RESET, 0);
	}
	free(cwd);
}
