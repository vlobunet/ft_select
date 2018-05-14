/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv_src.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 13:02:44 by vlobunet          #+#    #+#             */
/*   Updated: 2018/05/03 13:02:46 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

int		get_num_col(int col)
{
	print_head(col);
	return ((((col - 2) % (g_sel.mxs + 2) != 0) ? \
			((col - 2) / (g_sel.mxs + 2)) : \
			((col - 2) / (g_sel.mxs + 2)) - 1));
}

void	show_mes(int size)
{
	if (size == 0)
		ft_putendl_fd("  \033[38;05;95m...\033[0m", 0);
	else
		ft_putendl_fd("  \033[38;05;95mThis directory is empty\033[0m", 0);
}

int		get_serial_num(void)
{
	t_lst	*lst;
	int		i;

	i = 1;
	lst = g_sel.atr;
	while (lst && !lst->action)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int		get_i(int sw_row, int serial)
{
	int	i;

	i = 0;
	if (serial > (g_sel.col * (sw_row - 9)))
		while (serial > (g_sel.col * (sw_row - 9) + g_sel.col * ++i))
			;
	return ((i + 1) * g_sel.col);
}
