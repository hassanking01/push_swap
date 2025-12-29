/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:35:04 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:48:18 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		ft_printf("ss\n");
}
