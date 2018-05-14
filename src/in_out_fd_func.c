/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_fd_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 14:48:40 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/27 14:48:41 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	get_ar(char *name, t_lst **head, char *path)
{
	char		*tmp;

	tmp = ft_strjoin(path, "/");
	ft_lstad(&g_sel.atr, ft_lstnew_el(name, tmp));
	if (!(*head))
	{
		(*head) = g_sel.atr;
		(*head)->action = 1;
	}
	free(tmp);
	g_sel.coll++;
}

void	get_argv_list(char *path)
{
	DIR				*dir;
	struct dirent	*entry;
	t_lst			*head;

	head = NULL;
	g_sel.coll = 0;
	g_sel.mxs = 0;
	if ((dir = opendir(path)))
	{
		while (1)
		{
			entry = readdir(dir);
			if (!entry)
				break ;
			if (entry->d_name[0] != '.')
				get_ar(entry->d_name, &head, path);
		}
		closedir(dir);
	}
	g_sel.atr = head;
}

char	*ft_get_path(char *path)
{
	char	*last_slash;
	char	*parent;

	last_slash = ft_strrchr(path, '/');
	parent = ft_strndup(path, last_slash - path);
	return (parent);
}

void	run_out_fd(void)
{
	char	*cwd;
	char	*name;

	cwd = getcwd(NULL, 4096);
	name = ft_get_path(cwd);
	free(cwd);
	ft_lstdell_all();
	g_sel.atr = NULL;
	ft_strlen(name) != 0 ? get_argv_list(name) : get_argv_list("/");
	ft_strlen(name) != 0 ? chdir(name) : chdir("/");
	(g_sel.srch) ? free(g_sel.srch) : 0;
	g_sel.srch = NULL;
	g_sel.s_col = 0;
	print_argv(0);
	free(name);
}

void	run_in_fd(void)
{
	t_lst	*head;
	char	*str;

	head = g_sel.atr;
	while (!head->action)
		head = head->next;
	if (head->st_mode && !access(head->path, 4))
	{
		if (S_ISDIR(head->st_mode) || S_ISLNK(head->st_mode))
		{
			str = ft_strdup(head->path);
			head = g_sel.atr;
			ft_lstdell_all();
			g_sel.atr = NULL;
			get_argv_list(str);
			chdir(str);
			free(str);
		}
		(g_sel.srch) ? free(g_sel.srch) : 0;
		g_sel.srch = NULL;
		g_sel.s_col = 0;
		print_argv(0);
	}
}
