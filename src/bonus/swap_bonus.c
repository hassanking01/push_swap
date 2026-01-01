/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:35:04 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 14:43:32 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

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
		write(1, "sa\n", 3);
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
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag)
		write(1, "ss\n", 3);
}
