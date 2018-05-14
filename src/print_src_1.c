/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_src_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:25:45 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:25:45 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	show_message1(void)
{
	ft_putstr_fd(C_YELLO, 2);
	ft_putstr_fd("OK! Maybe it works! But you should ", 2);
	ft_putstr_fd("do something like this:\n", 2);
	ft_putstr_fd("./ft_select [arg1 arg2 arg3...]\n", 2);
	ft_putstr_fd("Come on! Try again!!!\n", 2);
	ft_putstr_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

void	show_message2(void)
{
	ft_putstr_fd(C_YELLO, 2);
	ft_putstr_fd("Oh no! You can not do it this way! You should use:\n", 2);
	ft_putstr_fd("./ft_select [arg1 arg2 arg3...]\n", 2);
	ft_putstr_fd("Come on! Try again!!!\n", 2);
	ft_putstr_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

int		printnbr(int i)
{
	return (write(0, &i, 1));
}
