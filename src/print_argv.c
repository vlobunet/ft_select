/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:01:48 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 19:01:49 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	set_arv_row(int sw_row, int serial, int sw_col)
{
	t_lst	*lst;
	int		i;
	int		o;

	lst = g_sel.atr;
	i = get_i(sw_row, serial);
	while (i--)
		lst = lst->next;
	show_mes(0);
	while (lst && g_sel.mxs + 2 < sw_col - 2 && --sw_row - 9 != 0)
	{
		i = -1;
		ft_putstr_fd("  ", 0);
		while (lst && ++i < g_sel.col)
		{
			o = g_sel.mxs - lst->size + 2;
			print_lst_atr(lst);
			while (o-- != 0)
				ft_putchar_fd(32, 0);
			lst = lst->next;
		}
		ft_putstr_fd("\n", 0);
	}
	show_mes(0);
}

void	print_a(int fd)
{
	struct winsize	s;
	int				i;
	int				o;
	t_lst			*head;

	if (ioctl(fd, TIOCGWINSZ, (char *)&s) < 0)
		return ;
	head = g_sel.atr;
	while (head && g_sel.mxs + 2 < s.ws_col - 2 && --s.ws_row - 8 != 0)
	{
		i = -1;
		ft_putstr_fd("  ", 0);
		while (head && ++i < g_sel.col)
		{
			o = g_sel.mxs - head->size + 2;
			print_lst_atr(head);
			while (o-- != 0)
				ft_putchar_fd(32, 0);
			head = head->next;
		}
		ft_putstr_fd("\n", 0);
	}
	(!g_sel.atr || s.ws_row - 8 == 0) ? show_mes(s.ws_row - 8) : 0;
}

void	print_messs(int col, int row)
{
	int	i;

	i = 0;
	while (i++ <= row / 2)
		ft_putchar_fd('\n', 0);
	while (i++ <= ((col / 2) - 7))
		ft_putchar_fd(' ', 0);
	ft_putendl_fd("\033[31mRESIZE WINDOW!", 0);
	g_sel.key = 0;
}

void	print_argv(int fd)
{
	struct winsize	s;
	int				serial;
	int				row;

	if (ioctl(fd, TIOCGWINSZ, (char *)&s) < 0)
		return ;
	tputs(tgetstr("cl", NULL), 1, printnbr);
	if (g_sel.mxs + 2 > s.ws_col - 4 || s.ws_row <= 10)
		print_messs(s.ws_col, s.ws_row);
	else
	{
		g_sel.key = 1;
		g_sel.col = get_num_col(s.ws_col);
		serial = get_serial_num();
		row = (serial % g_sel.col != 0) ? \
		(serial / g_sel.col) + 1 : (serial / g_sel.col);
		if (row > s.ws_row - 9)
			set_arv_row(s.ws_row, serial, s.ws_col);
		else if (g_sel.atr)
			print_a(0);
		print_footer(s.ws_col);
	}
}
