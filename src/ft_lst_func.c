/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:13:28 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:13:30 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

char	*ft_get_name(char *str)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (str[i])
	{
		str[i] == '/' ? m = i : 0;
		i++;
	}
	if (m == 0 && str[0] == '/')
		return (str + 1);
	else
		return (str + m);
}

t_lst	*ft_lstnew_el(char *str, char *path)
{
	t_lst		*lst;
	struct stat	st;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->content = (str[0] == '/' && !str[1] ? ft_strdup("/") :\
	ft_strdup(ft_get_name(str)));
	lst->path = ft_strjoin(path, str);
	if (lstat(lst->path, &st) != -1)
		lst->st_mode = st.st_mode;
	lst->cur = 0;
	lst->action = 0;
	lst->prev = NULL;
	lst->next = NULL;
	lst->size = ft_strlen(lst->content);
	(g_sel.mxs < lst->size) ? g_sel.mxs = lst->size : 0;
	return (lst);
}

void	ft_lstad(t_lst **alst, t_lst *new_lst)
{
	if (*alst)
	{
		(*alst)->next = new_lst;
		new_lst->prev = *alst;
	}
	*alst = new_lst;
}

void	ft_lstdell_all(void)
{
	t_lst	*head;

	if (!g_sel.atr)
		return ;
	while (g_sel.atr->next)
	{
		head = g_sel.atr->next;
		free(g_sel.atr->content);
		free(g_sel.atr->path);
		g_sel.atr->next->prev = NULL;
		free(g_sel.atr);
		g_sel.atr = head;
	}
	free(g_sel.atr->content);
	free(g_sel.atr->path);
	free(g_sel.atr);
}
