CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

m_fils = ft_printf/ft_printf.c \
		ft_printf/ft_pustr.c   \
		ft_printf/ft_putchar.c  \
		ft_printf/ft_putnbr.c    \
		ft_printf/ft_putptr.c     \
		ft_printf/ft_putunsigned_hex.c \
		src/mandatory/sort_utils.c                \
		src/operations/push.c 			\
		src/operations/reverce_rotate.c \
		src/operations/rotate.c 		\
		src/operations/swap.c 			\
		src/mandatory/ft_strndup.c       \
		src/mandatory/stack_utils.c 		\
		src/mandatory/sort_funcs.c 				\
		src/mandatory/set_push_swap.c				\
		src/mandatory/push_swap.c 				\
		src/mandatory/ft_atoi.c 					\
		src/mandatory/ft_spit.c 					\
		src/mandatory/handel_error.c 				\
		src/mandatory/lst_utils.c 				\
		src/mandatory/main.c

b_fils = 
obj_files =$(m_fils:.c=.o)

b_fils = ft_printf/ft_printf.c \
		ft_printf/ft_pustr.c   \
		ft_printf/ft_putchar.c  \
		ft_printf/ft_putnbr.c    \
		ft_printf/ft_putptr.c     \
		ft_printf/ft_putunsigned_hex.c \
		src/mandatory/sort_utils.c                \
		src/mandatory/ft_atoi.c 					\
		src/mandatory/ft_spit.c 					\
		src/mandatory/ft_strndup.c       \
		src/operations/push.c 			\
		src/operations/reverce_rotate.c \
		src/operations/rotate.c 		\
		src/operations/swap.c 			\
		src/mandatory/stack_utils.c 		\
		src/mandatory/sort_funcs.c 				\
		src/mandatory/lst_utils.c 				\
		src/bonus/check_ops.c						\
		get_next_line/get_next_line_utils.c         \
		get_next_line/get_next_line.c               \
		src/mandatory/handel_error.c 				\
		src/bonus/main.c

bonus_obj_files =$(b_fils:.c=.o)

BONUS_NAME= checker

$(NAME): $(obj_files)
	$(CC) $(CFLAGS) $(obj_files) -o $(NAME)
bonus: .bonus

.bonus: $(bonus_obj_files)
	@touch .bonus
	$(CC) $(CFLAGS) $(bonus_obj_files) -o $(BONUS_NAME)
all:$(NAME)

clean:
	rm -rf $(obj_files) $(bonus_obj_files) 
	

fclean:clean
	rm -f $(NAME) $(BONUS_NAME)
	@rm -f .bonus

re:fclean all

.SECONDERY:  $(obj_files) 
