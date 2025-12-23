/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:28:30 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/18 16:46:58 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	t_stack	*ptr;

	if (!a || !*a)
		return ;
	ptr = *a;
	*a = (*a)->next;
	ptr->next = (*a)->next;
	(*a)->next = ptr;
	if (flag)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	t_stack	*ptr;

	if (!b || !*b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = (*b)->next;
	(*b)->next = ptr;
	if (flag)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!a || !b || !*b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = (*a);
	(*a) = ptr;
	ft_printf("pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*ptr;

	if (!a || !b || !*a)
		return ;
	ptr = (*a);
	*a = (*a)->next;
	ptr->next = (*b);
	(*b) = ptr;
	ft_printf("pb\n");
}
