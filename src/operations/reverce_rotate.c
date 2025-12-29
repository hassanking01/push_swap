/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverce_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:34:32 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:48:03 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!a || !(*a))
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
		ft_printf("rra\n");
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*ptr;
	t_stack	*tmp;

	if (!b || !(*b))
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
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag)
		ft_printf("rrr\n");
}
