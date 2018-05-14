/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 19:03:19 by vlobunet          #+#    #+#             */
/*   Updated: 2018/04/22 19:03:21 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <termcap.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ftw.h>
# include <unistd.h>
# include <sys/param.h>

# define C_RESET		"\033[0m"

# define C_ERROR		"\033[31m"
# define CU_ERROR		"\033[7;31m"
# define CR_ERROR		"\033[4;31m"
# define CUR_ERROR		"\033[7;4;31m"

# define C_GREEN		"\033[32m"
# define CU_GREEN		"\033[7;32m"
# define CR_GREEN		"\033[4;32m"
# define CUR_GREEN		"\033[7;4;32m"

# define C_YELLO		"\033[38;05;226m"
# define CU_YELLO		"\033[7;33m"
# define CR_YELLO		"\033[4;38;05;226m"
# define CUR_YELLO		"\033[7;4;33m"

# define C_SINIY		"\033[34m"
# define CU_SINIY		"\033[7;34m"
# define CR_SINIY		"\033[4;34m"
# define CUR_SINIY		"\033[7;4;34m"

# define C_FIOLE		"\033[35m"
# define CU_FIOLE		"\033[7;35m"
# define CR_FIOLE		"\033[4;35m"
# define CUR_FIOLE		"\033[7;4;35m"

# define C_GOLYB		"\033[03;38;05;51m"
# define CU_GOLYB		"\033[7;36m"
# define CR_GOLYB		"\033[4;36m"
# define CUR_GOLYB		"\033[7;4;36m"

# define C_WHIT			"\033[38;05;15m"
# define CU_WHIT		"\033[7;37m"
# define CR_WHIT		"\033[4;38;05;15m"
# define CUR_WHIT		"\033[7;4;37m"
# define CB_WHIT		"\033[5;37m"

# define C_HELP			"\033[37;46m"
# define C_MENU			"\033[37;44m"

typedef struct		s_lst
{
	char			*content;
	char			*path;
	int				num;
	int				size;
	mode_t			st_mode;
	int				cur;
	int				ws;
	int				action;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_select
{
	char			*name_t;
	int				key;
	struct termios	tty;
	struct termios	savetty;
	int				col;
	int				coll;
	int				mxs;
	t_lst			*atr;
	char			*srch;
	int				s_col;
}					t_sel;

t_sel				g_sel;

# define KEY_RIGHT		4414235
# define KEY_LEFT		4479771
# define KEY_UP			4283163
# define KEY_DOWN		4348699
# define KEY_BACK		127
# define KEY_TAB		9
# define KEY_DEL		42

void				run_exit(void);
void				run_left(void);
void				run_right(void);
int					get_i(int sw_row, int serial);
void				run_up(void);
void				run_dw(void);
void				run_backspace(void);
int					get_num_col(int col);
void				ft_backspace(void);
void				ft_resize(char buff);
void				run_in_fd();
void				run_out_fd();
void				get_argv(char **argv, char *path);

void				ft_freestrarr(char **arr);
void				ft_scanf(int fd);

void				print_error_name_t(void);
void				print_error_data(int i);
void				print_error_term(void);
void				print_help_header(int size);
int					get_serial_num(void);
void				print_lst_atr(t_lst	*lst);
void				print_argv(int fd);
void				print_head(int size);
void				print_footer(int size);
void				show_message1(void);
void				show_message2(void);
int					printnbr(int i);
void				show_mes(int size);

void				get_signal(void);
void				exit_signal(void);

void				ft_lstad(t_lst **alst, t_lst *new_lst);
t_lst				*ft_lstnew_el(char *str, char *path);
void				ft_lstdell_all(void);
void				res_default_settings(struct termios savetty);
struct termios		get_default_settings(void);

#endif
