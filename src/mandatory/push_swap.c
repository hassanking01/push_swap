/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:25:03 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 09:45:39 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_big_pos(t_stack *ptr)
{
	int		i;
	t_stack	*tmp;
	int		big;

	i = 0;
	big = INT_MIN;
	tmp = ptr;
	while (ptr)
	{
		if (ptr->value > big)
		{
			big = ptr->value;
		}
		ptr = ptr->next;
	}
	while (tmp->value != big)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_stack	*find(t_stack *b, int index)
{
	while (index--)
		b = b->next;
	return (b);
}

void	big_to_head(t_stack **b, int i)
{
	int		size;
	t_stack	*targit;

	targit = find(*b, i);
	size = lstsize(b);
	if (i > size / 2)
	{
		while ((*b) != targit)
			rrb(b, 1);
	}
	else
	{
		while ((*b) != targit)
			rb(b, 1);
	}
}

void	finish_push_swap(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (*b)
	{
		i = get_big_pos(*b);
		big_to_head(b, i);
		pa(a, b, 1);
	}
}

void	push_swap(t_stack **a, t_stack **b, int chunk_size)
{
	int	i;

	i = 0;
	if (chunk_size > 100)
		chunk_size = 35;
	else
		chunk_size = 15;
	while ((*a))
	{
		if ((*a)->index <= i)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, 1);
			i++;
		}
		else
			ra(a, 1);
	}
	finish_push_swap(a, b);
}
