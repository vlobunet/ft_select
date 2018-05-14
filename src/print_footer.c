/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_footer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:55:18 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/27 14:55:18 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	print_h(int size)
{
	int		i;
	int		tmp;
	char	*str;

	i = 0;
	str = ft_itoa(g_sel.s_col);
	tmp = 13 + 7 + ft_strlen(str) + ft_strlen(g_sel.srch);
	free(str);
	if (tmp > size)
		return ;
	ft_putstr_fd("║ Search: ", 0);
	ft_putstr_fd(g_sel.srch, 0);
	ft_putstr_fd(CB_WHIT, 0);
	ft_putchar_fd('|', 0);
	ft_putstr_fd(C_RESET, 0);
	ft_putstr_fd(C_MENU, 0);
	while (tmp++ < size)
		ft_putstr_fd(" ", 0);
	ft_putstr_fd("found: ", 0);
	ft_putnbr_fd(g_sel.s_col, 0);
	ft_putstr_fd(" ║\n", 0);
}

void	print_footer(int size)
{
	int	i;

	i = -1;
	(!g_sel.srch) ? g_sel.srch = ft_strnew(0) : 0;
	ft_putstr_fd("\n", 0);
	ft_putstr_fd(C_MENU, 0);
	ft_putstr_fd("╔", 0);
	while (++i != size - 2)
		ft_putstr_fd("═", 0);
	ft_putstr_fd("╗", 0);
	i = -1;
	print_h(size);
	ft_putstr_fd("╚", 0);
	while (++i != size - 2)
		ft_putstr_fd("═", 0);
	ft_putstr_fd("╝", 0);
	ft_putstr_fd(C_RESET, 0);
}
