/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:14:37 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:14:38 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	run_space(void)
{
	t_lst	*head;

	if (!g_sel.atr)
		return ;
	head = g_sel.atr;
	while (!head->action)
		head = head->next;
	if (head->cur == 1)
		head->cur = 0;
	else
		head->cur = 1;
	run_right();
}

void	get_all(int key)
{
	t_lst	*src;

	src = g_sel.atr;
	if (key == 1)
		while (src)
		{
			if (!src->cur)
				src->cur = 1;
			src = src->next;
		}
	else
		while (src)
		{
			if (src->cur)
				src->cur = 0;
			src = src->next;
		}
	print_argv(0);
}

void	ft_scanf(int fd)
{
	int	key;

	while (1)
	{
		read(fd, &key, 8);
		if ((char)key == '\n')
			break ;
		(key == KEY_RIGHT && g_sel.atr && g_sel.key) ? \
		run_right() : 0;
		(key == KEY_LEFT && g_sel.atr && g_sel.key) ? run_left() : 0;
		(key == KEY_UP && g_sel.atr && g_sel.key) ? run_up() : 0;
		(key == KEY_DOWN && g_sel.atr && g_sel.key) ? run_dw() : 0;
		((char)key == 32 && g_sel.atr && g_sel.key) ? run_space() : 0;
		((char)key == KEY_BACK && g_sel.key) ? run_backspace() : 0;
		((char)key > 32 && (char)key < 127 && (char)key != 43 && \
			(char)key != 42 && (char)key != 45 && g_sel.key) ? \
		ft_resize((char)key) : 0;
		((char)key == 43 && g_sel.atr && g_sel.key) ? run_in_fd() : 0;
		((char)key == 45 && g_sel.key) ? run_out_fd() : 0;
		((char)key == 42 && g_sel.key) ? ft_backspace() : 0;
		((key == 1 || key == 24) && g_sel.atr && g_sel.key) ? get_all(key) : 0;
		(key == 27) ? exit_signal() : 0;
		key = 0;
	}
}
