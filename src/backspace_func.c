/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backspace_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:12:36 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:12:36 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	del_one_of_two(void)
{
	t_lst *head;

	if (g_sel.atr->action != 1)
		head = g_sel.atr->next;
	else
	{
		head = g_sel.atr;
		g_sel.atr = g_sel.atr->next;
	}
	free(g_sel.atr->content);
	free(g_sel.atr->path);
	free(g_sel.atr);
	g_sel.atr = head;
	g_sel.atr->next = NULL;
	g_sel.atr->prev = NULL;
}

void	del_one_of_more(void)
{
	while (!g_sel.atr->action)
		g_sel.atr = g_sel.atr->next;
	if (!g_sel.atr->prev)
	{
		while (g_sel.atr->next)
			g_sel.atr = g_sel.atr->next;
		g_sel.atr->prev->next = NULL;
	}
	else
	{
		g_sel.atr = g_sel.atr->prev;
		if (!g_sel.atr->prev)
			g_sel.atr->next->prev = NULL;
		else
		{
			g_sel.atr->next->prev = g_sel.atr->prev;
			g_sel.atr->prev->next = g_sel.atr->next;
		}
	}
	g_sel.atr->next = NULL;
	g_sel.atr->prev = NULL;
	free(g_sel.atr->content);
	free(g_sel.atr->path);
	free(g_sel.atr);
}

void	del_one(void)
{
	free(g_sel.atr->content);
	free(g_sel.atr->path);
	free(g_sel.atr);
	g_sel.atr = NULL;
	exit_signal();
}

void	run_backspace(void)
{
	t_lst *head;

	if (!g_sel.atr)
		exit_signal();
	if (!g_sel.atr->next && !g_sel.atr->prev)
	{
		del_one();
		return ;
	}
	run_right();
	if (g_sel.atr->next && !g_sel.atr->next->next)
		del_one_of_two();
	else
	{
		if (g_sel.atr->next->action == 1)
			head = g_sel.atr->next;
		else
			head = g_sel.atr;
		del_one_of_more();
		g_sel.atr = head;
	}
	g_sel.coll = g_sel.coll - 1;
	print_argv(0);
}
