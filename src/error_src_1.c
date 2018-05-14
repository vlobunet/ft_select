/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_src_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:09:35 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:09:36 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

void	print_error_name_t(void)
{
	ft_putstr_fd(C_ERROR, 2);
	ft_putstr_fd("ERROR: The name of the terminal was not found!\n", 2);
	ft_putstr_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

void	print_error_data(int i)
{
	ft_putstr_fd(C_ERROR, 2);
	if (i == -1)
		ft_putstr_fd("ERROR: Description of the \
			current terminal was not found!\n", 2);
	else if (i == 0)
		ft_putstr_fd("ERROR: Description of the current terminal empty!\n", 2);
	ft_putstr_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}

void	print_error_term(void)
{
	ft_putstr_fd(C_ERROR, 2);
	ft_putstr_fd("ERROR: The device is not a terminal!\n", 2);
	ft_putstr_fd(C_RESET, 2);
	exit(EXIT_FAILURE);
}
