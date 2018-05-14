/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_signal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:51:05 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 18:51:06 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

static void	suspend(void)
{
	res_default_settings(g_sel.savetty);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

void		exit_signal(void)
{
	res_default_settings(g_sel.savetty);
	ft_lstdell_all();
	exit(EXIT_SUCCESS);
}

void		sig(int signo)
{
	if (signo == SIGWINCH)
		print_argv(0);
	else if (signo == SIGTSTP)
		suspend();
	else if (signo == SIGINT || signo == SIGABRT || signo == SIGSTOP ||\
		signo == SIGKILL || signo == SIGQUIT || signo == SIGHUP ||\
		signo == SIGTERM || signo == SIGSEGV || signo == SIGFPE ||\
		signo == SIGALRM || signo == SIGUSR1 || signo == SIGUSR2)
		exit_signal();
	else if (signo == SIGCONT)
	{
		g_sel.savetty = get_default_settings();
		get_signal();
		print_argv(0);
	}
}

void		get_signal(void)
{
	signal(SIGWINCH, sig);
	signal(SIGTSTP, sig);
	signal(SIGINT, sig);
	signal(SIGABRT, sig);
	signal(SIGSTOP, sig);
	signal(SIGKILL, sig);
	signal(SIGQUIT, sig);
	signal(SIGHUP, sig);
	signal(SIGTERM, sig);
	signal(SIGSEGV, sig);
	signal(SIGFPE, sig);
	signal(SIGALRM, sig);
	signal(SIGUSR1, sig);
	signal(SIGUSR2, sig);
	signal(SIGCONT, sig);
}
