/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst_atr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:30:28 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:30:29 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	print_s_iflnk(t_lst *lst)
{
	(lst->action && lst->cur) ? ft_putstr_fd(CUR_GOLYB, 0) : 0;
	(!lst->action && lst->cur) ? ft_putstr_fd(CU_GOLYB, 0) : 0;
	(lst->action && !lst->cur) ? ft_putstr_fd(CR_GOLYB, 0) : 0;
	(!lst->action && !lst->cur) ? ft_putstr_fd(C_GOLYB, 0) : 0;
	ft_putstr_fd(lst->content, 0);
	ft_putstr_fd(C_RESET, 0);
}

void	print_s_freg(t_lst *lst)
{
	(lst->action && lst->cur) ? ft_putstr_fd(CUR_WHIT, 0) : 0;
	(!lst->action && lst->cur) ? ft_putstr_fd(CU_WHIT, 0) : 0;
	(lst->action && !lst->cur) ? ft_putstr_fd(CR_WHIT, 0) : 0;
	(!lst->action && !lst->cur) ? ft_putstr_fd(C_WHIT, 0) : 0;
	ft_putstr_fd(lst->content, 0);
	ft_putstr_fd(C_RESET, 0);
}

void	print_s_ifdir(t_lst *lst)
{
	(lst->action && lst->cur) ? ft_putstr_fd(CUR_YELLO, 0) : 0;
	(!lst->action && lst->cur) ? ft_putstr_fd(CU_YELLO, 0) : 0;
	(lst->action && !lst->cur) ? ft_putstr_fd(CR_YELLO, 0) : 0;
	(!lst->action && !lst->cur) ? ft_putstr_fd(C_YELLO, 0) : 0;
	ft_putstr_fd(lst->content, 0);
	ft_putstr_fd(C_RESET, 0);
}

void	print_lst_mode(t_lst *lst)
{
	(S_ISLNK(lst->st_mode)) ? print_s_iflnk(lst) : 0;
	(S_ISREG(lst->st_mode)) ? print_s_freg(lst) : 0;
	(S_ISDIR(lst->st_mode)) ? print_s_ifdir(lst) : 0;
	if ((S_ISBLK(lst->st_mode)) || (S_ISBLK(lst->st_mode)) ||\
		(S_ISBLK(lst->st_mode)) || S_ISSOCK(lst->st_mode))
	{
		(lst->cur && lst->action) ? ft_putstr_fd(CUR_FIOLE, 0) : 0;
		(!lst->cur && lst->action) ? ft_putstr_fd(CR_FIOLE, 0) : 0;
		(lst->cur && !lst->action) ? ft_putstr_fd(CU_FIOLE, 0) : 0;
		(!lst->cur && !lst->action) ? ft_putstr_fd(C_FIOLE, 0) : 0;
		ft_putstr_fd(lst->content, 0);
		ft_putstr_fd(C_RESET, 0);
	}
	if (S_ISCHR(lst->st_mode))
	{
		(lst->cur && lst->action) ? ft_putstr_fd(CUR_SINIY, 0) : 0;
		(!lst->cur && lst->action) ? ft_putstr_fd(CR_SINIY, 0) : 0;
		(lst->cur && !lst->action) ? ft_putstr_fd(CU_SINIY, 0) : 0;
		(!lst->cur && !lst->action) ? ft_putstr_fd(C_SINIY, 0) : 0;
		ft_putstr_fd(lst->content, 0);
		ft_putstr_fd(C_RESET, 0);
	}
}

void	print_lst_atr(t_lst *lst)
{
	if (lst->st_mode && !access(lst->path, 4))
		print_lst_mode(lst);
	else
	{
		if (access(lst->path, 0))
		{
			(lst->cur && lst->action) ? ft_putstr_fd(CUR_GREEN, 0) : 0;
			(!lst->cur && lst->action) ? ft_putstr_fd(CR_GREEN, 0) : 0;
			(lst->cur && !lst->action) ? ft_putstr_fd(CU_GREEN, 0) : 0;
			(!lst->cur && !lst->action) ? ft_putstr_fd(C_GREEN, 0) : 0;
		}
		else if (access(lst->path, 4))
		{
			(lst->cur && lst->action) ? ft_putstr_fd(CUR_ERROR, 0) : 0;
			(!lst->cur && lst->action) ? ft_putstr_fd(CR_ERROR, 0) : 0;
			(lst->cur && !lst->action) ? ft_putstr_fd(CU_ERROR, 0) : 0;
			(!lst->cur && !lst->action) ? ft_putstr_fd(C_ERROR, 0) : 0;
		}
		ft_putstr_fd(lst->content, 0);
		ft_putstr_fd(C_RESET, 0);
	}
}
