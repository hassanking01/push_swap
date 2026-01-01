/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:34:12 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/24 15:34:26 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack	*ptr;

	if (!a || !b || !*b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = (*a);
	(*a) = ptr;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int flag)
{
	t_stack	*ptr;

	if (!a || !b || !*a)
		return ;
	ptr = (*a);
	*a = (*a)->next;
	ptr->next = (*b);
	(*b) = ptr;
	if (flag)
		write(1, "pb\n", 3);
}
