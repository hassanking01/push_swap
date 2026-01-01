CC = cc
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror

m_fils = src/mandatory/sort_utils.c                \
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

b_fils = src/mandatory/sort_utils.c                \
		src/bonus/ft_atoi_bonus.c 					\
		src/bonus/ft_spit_bonus.c 					\
		src/bonus/ft_strndup_bonus.c       \
		src/bonus/push_bonus.c 			\
		src/bonus/reverce_rotate_bonus.c \
		src/bonus/rotate_bonus.c 		\
		src/bonus/swap_bonus.c 			\
		src/bonus/stack_utils_bonus.c 		\
		src/bonus/lst_utils_bonus.c 				\
		src/bonus/check_ops_bonus.c				\
		src/bonus/get_next_line_utils_bonus.c         \
		src/bonus/get_next_line_bonus.c               \
		src/bonus/handel_error_bonus.c 				\
		src/bonus/main_bonus.c

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
