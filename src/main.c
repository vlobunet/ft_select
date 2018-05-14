/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:21:04 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/10 17:21:05 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_select.h"

struct termios	get_default_settings(void)
{
	char			buf[1024];
	struct termios	savetty;

	((g_sel.name_t = getenv("TERM")) == NULL) ? print_error_name_t() : 0;
	!isatty(0) ? print_error_term() : 0;
	((tgetent(buf, g_sel.name_t)) == -1) ? print_error_data(-1) : 0;
	((tgetent(buf, g_sel.name_t)) == 0) ? print_error_data(0) : 0;
	tcgetattr(0, &g_sel.tty);
	savetty = g_sel.tty;
	g_sel.tty.c_lflag &= ~(ICANON | ECHO);
	g_sel.tty.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &g_sel.tty);
	tputs(tgetstr("ti", NULL), 1, printnbr);
	tputs(tgetstr("vi", NULL), 1, printnbr);
	return (savetty);
}

void			res_default_settings(struct termios savetty)
{
	tcsetattr(0, TCSANOW, &savetty);
	tputs(tgetstr("ve", NULL), 1, printnbr);
	tputs(tgetstr("te", NULL), 1, printnbr);
}

void			get_argv(char **argv, char *path)
{
	int		i;
	t_lst	*head;

	head = NULL;
	i = -1;
	while (argv[++i])
	{
		ft_lstad(&g_sel.atr, ft_lstnew_el(argv[i], path));
		if (!head)
		{
			head = g_sel.atr;
			head->action = 1;
		}
	}
	g_sel.coll = i;
	g_sel.atr = head;
}

void			ft_print_stdout(void)
{
	t_lst	*head;
	int		coll;

	coll = 0;
	if (!g_sel.atr)
		return ;
	head = g_sel.atr;
	while (head)
	{
		if (head->cur && ++coll)
		{
			ft_putstr_fd(head->path, 1);
			ft_putchar_fd(32, 1);
		}
		head = head->next;
	}
}

int				main(int argc, char **argv)
{
	argv++;
	(argc < 2) ? show_message1() : 0;
	g_sel.savetty = get_default_settings();
	get_argv(argv, "");
	get_signal();
	print_argv(0);
	ft_scanf(0);
	res_default_settings(g_sel.savetty);
	ft_print_stdout();
	ft_lstdell_all();
	return (0);
}
