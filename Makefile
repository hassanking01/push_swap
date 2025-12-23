CC = cc
NAME = push_swap
CFLAGS =   -g  ##-Wall -Wextra -Werror

fils = lst_utils.c \
			main.c \
			moves_1.c \
			moves_2.c  \
			sort_utils.c\
			sort_funcs.c \
			ft_printf/ft_printf.c \
			ft_printf/ft_pustr.c    \
			ft_printf/ft_putchar.c   \
  			ft_printf/ft_putnbr.c     \
			ft_printf/ft_putptr.c      \
			ft_printf/ft_putunsigned_hex.c 
obj_files =$(fils:.c=.o)

makeandclean:all clean  ## TODO mse7 haschi

$(NAME): $(obj_files)
	$(CC) $(CFLAGS) $(obj_files) -o $(NAME)

debug:$(NAME)			## TODO remove this line

all:$(NAME)
clean:
	rm -f $(obj_files)
fclean:clean
	rm -f $(NAME)
re:fclean all