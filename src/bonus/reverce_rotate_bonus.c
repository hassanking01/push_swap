/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverce_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:34:32 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 14:43:02 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	ptr = *a;
	while (ptr->next)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	ptr->next = *a;
	*a = ptr;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!b || !(*b) || !(*b)->next)
		return ;
	ptr = *b;
	while (ptr->next)
	{
		tmp = ptr;
		ptr = ptr->next;
	}
	tmp->next = NULL;
	ptr->next = *b;
	*b = ptr;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		write(1, "rrr\n", 4);
}
