/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:29:31 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 14:41:25 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# define INT_MIN -2147483648
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}					t_stack;

void				set_indexs(t_stack *a);
long				ft_atoi(char *str);
int					free_re(char **ptr);
void				set_stack_a(t_stack **head, char **av);
void				ft_clean(char **av, t_stack **head);
void				ft_lstclean(t_stack **head);
t_stack				*lst_new(int value);
void				lstaddack(t_stack **head, t_stack *new_node);
int					is_sorted(t_stack *head);
void				set_stack_a(t_stack **head, char **av);
void				set_indexs(t_stack *a);
void				set_push_swap(t_stack **a, t_stack **b);
char				**ft_split(char **str);
int					check_error(char **av);
long				ft_atoi(char *str);
int					lstsize(t_stack **head);
void				sort_2(t_stack **a);
void				sort_3(t_stack **a);
void				sort_5(t_stack **a, t_stack **b, int size);
void				push_swap(t_stack **a, t_stack **b, int chunk_size);
char				*ft_strndup(char *str, int size);

int					check_rotate(char *str, t_stack **a, t_stack **b);
int					check_rev_rotate(char *str, t_stack **a, t_stack **b);
int					check_push(char *str, t_stack **a, t_stack **b);
int					check_swap(char *str, t_stack **a, t_stack **b);
void				sa(t_stack **a, int flag);
void				sb(t_stack **b, int flag);
void				ss(t_stack **a, t_stack **b, int flag);
void				pa(t_stack **a, t_stack **b, int flag);
void				pb(t_stack **a, t_stack **b, int flag);
void				lstaddack(t_stack **head, t_stack *new_node);
void				ra(t_stack **a, int flag);
void				rb(t_stack **b, int falg);
void				rr(t_stack **a, t_stack **b, int flag);
void				rra(t_stack **a, int flag);
void				rrb(t_stack **b, int flag);
void				rrr(t_stack **a, t_stack **b, int flag);

char				*ft_strdup(char *str);
int					read_from_fd(int fd, char **remainder);
char				*get_next_line(int fd);
char				*ft_join(char *s1, char *s2);
char				*ft_strchr(const char *str, char c);
size_t				ft_strlen(const char *str);
#endif
