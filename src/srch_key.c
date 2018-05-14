/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srch_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 15:28:31 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/27 15:28:57 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	go_in(void)
{
	while (ft_strncmp(g_sel.srch, g_sel.atr->content,\
		ft_strlen(g_sel.srch)) && !g_sel.atr->action)
		g_sel.atr = g_sel.atr->next;
	if (g_sel.atr->action && !ft_strncmp(g_sel.srch,\
		g_sel.atr->content, ft_strlen(g_sel.srch)))
		;
	else if (g_sel.atr->action)
	{
		g_sel.atr->action = 0;
		while (ft_strncmp(g_sel.srch, g_sel.atr->content,\
			ft_strlen(g_sel.srch)))
			g_sel.atr = g_sel.atr->next;
		g_sel.atr->action = 1;
	}
	else
	{
		g_sel.atr->action = 1;
		g_sel.atr = g_sel.atr->next;
		while (!g_sel.atr->action)
			g_sel.atr = g_sel.atr->next;
		g_sel.atr->action = 0;
	}
}

void	set_action(void)
{
	t_lst	*head;

	if (!g_sel.atr)
		return ;
	head = g_sel.atr;
	while (g_sel.atr->action != 1)
		g_sel.atr = g_sel.atr->next;
	g_sel.atr->action = 0;
	g_sel.atr = head;
	g_sel.atr->action = 1;
}

void	get_srch_el(void)
{
	t_lst	*head;

	g_sel.s_col = 0;
	if (ft_strlen(g_sel.srch) == 0)
	{
		set_action();
		return ;
	}
	head = g_sel.atr;
	while (g_sel.atr)
	{
		if (!ft_strncmp(g_sel.srch, g_sel.atr->content,\
			ft_strlen(g_sel.srch)))
			g_sel.s_col++;
		g_sel.atr = g_sel.atr->next;
	}
	g_sel.atr = head;
	(g_sel.s_col != 0) ? go_in() : 0;
	g_sel.atr = head;
}

void	ft_resize(char buff)
{
	char	*dup;
	int		i;

	i = 0;
	if (g_sel.srch)
	{
		dup = ft_strnew(ft_strlen(g_sel.srch) + 1);
		while (g_sel.srch[i] != '\0')
		{
			dup[i] = g_sel.srch[i];
			i++;
		}
		dup[i] = buff;
		dup[i + 1] = '\0';
		free(g_sel.srch);
		g_sel.srch = ft_strdup(dup);
		free(dup);
		get_srch_el();
		print_argv(0);
	}
}

void	ft_backspace(void)
{
	char	*command;
	int		j;
	int		size;

	j = -1;
	size = (int)ft_strlen(g_sel.srch);
	if (size - 1 < 0)
		return ;
	command = ft_strnew(size - 1);
	while (++j != size - 1)
		command[j] = g_sel.srch[j];
	command[j] = '\0';
	free(g_sel.srch);
	g_sel.srch = ft_strdup(command);
	free(command);
	get_srch_el();
	print_argv(0);
}
