NAME	= ft_select
SRCS	= src/main.c src/error_src_1.c src/ft_scanf.c \
			src/print_src_1.c src/get_signal.c src/ft_lst_func.c \
			src/arrow_func.c src/backspace_func.c src/print_footer.c\
			src/print_lst_atr.c src/print_argv.c src/print_head.c \
			src/srch_key.c src/in_out_fd_func.c src/print_argv_src.c
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror -g -O3
HEADER	= includes/ft_select.h

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/
	@gcc $(OBJS) -o $(NAME) -L libft/ -lft -ltermcap

%.o: %.c $(HEADER)
	@cc -c $< -o $@ $(FLAGS)
	@echo  "█\c)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)

re: fclean $(NAME)
