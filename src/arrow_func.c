/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:11:47 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:11:48 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	run_left(void)
{
	t_lst	*head;

	head = g_sel.atr;
	while (!head->action)
		head = head->next;
	head->action = 0;
	if (!head->prev)
		while (head->next)
			head = head->next;
	else
		head = head->prev;
	head->action = 1;
	print_argv(0);
}

void	run_right(void)
{
	t_lst	*head;

	head = g_sel.atr;
	while (!head->action)
		head = head->next;
	head->action = 0;
	if (!head->next)
		head = g_sel.atr;
	else
		head = head->next;
	head->action = 1;
	print_argv(0);
}

void	run_up(void)
{
	int		i;
	int		j;
	t_lst	*head;

	i = 0;
	j = 0;
	head = g_sel.atr;
	while (++i && !head->action)
		head = head->next;
	head->action = 0;
	if (i - g_sel.col <= 0)
	{
		j = (((g_sel.coll % g_sel.col) != 0) ?\
		((g_sel.coll / g_sel.col) + 1) : (g_sel.coll / g_sel.col));
		j = ((i + ((j - 1) * g_sel.col) > g_sel.coll) ?\
		((j - 2) * g_sel.col) : ((j - 1) * g_sel.col));
		while (j--)
			head = head->next;
	}
	else
		while (head && j++ != g_sel.col)
			head = head->prev;
	head->action = 1;
	print_argv(0);
}

void	run_dw(void)
{
	int		i;
	int		j;
	t_lst	*head;

	i = 0;
	j = 0;
	head = g_sel.atr;
	while (++i && !head->action)
		head = head->next;
	head->action = 0;
	if (i + g_sel.col > g_sel.coll)
	{
		while (((i + j) % g_sel.col) != 0)
			j++;
		i = g_sel.col - j;
		head = g_sel.atr;
		while (--i)
			head = head->next;
	}
	else
		while (head && j++ != g_sel.col)
			head = head->next;
	head->action = 1;
	print_argv(0);
}
