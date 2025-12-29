/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:34:50 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:48:10 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*ptr;

	if (!a || !(*a))
		return ;
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = NULL;
	lstaddack(a, ptr);
	if (flag)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int falg)
{
	t_stack	*ptr;

	if (!b || !(*b))
		return ;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = NULL;
	lstaddack(b, ptr);
	if (falg)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag)
		ft_printf("rr\n");
}
