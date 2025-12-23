/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:29:31 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/18 16:50:29 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf/ft_printf.h"
# include <stdlib.h>

typedef struct s_stack
{
	int				index;
	int				value;
	struct s_stack	*next;
}					t_stack;

void				sa(t_stack **a, int flag);
void				sb(t_stack **b, int flag);
void				ss(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void lstaddack(t_stack ** head, t_stack * new);
void ra(t_stack ** a, int flag);
void rb(t_stack ** b, int falg);
void rr(t_stack ** a ,t_stack ** b);
void rra(t_stack ** a, int flag);
void rrb(t_stack ** b, int flag);
void rrr(t_stack ** a, t_stack ** b);
void set_indexs(t_stack * a);
long ft_atoi(char * str);
int free_re(char ** ptr);
void set_stack_a(t_stack ** head, char ** av , int is_one);
void ft_clean(char ** av, t_stack ** head, int is_one);
void ft_lstclean(t_stack ** head);
t_stack *lst_new(int value);
void lstaddack(t_stack ** head, t_stack * new);
int is_sorted(t_stack * head);
int lstsize(t_stack ** head);
void sort_2(t_stack ** a);
void sort_3(t_stack ** a);
void sort_5(t_stack ** a , t_stack **  b, int size);
void push_swap(t_stack ** a, t_stack ** b );
#endif
