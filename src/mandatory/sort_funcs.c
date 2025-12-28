/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:30:37 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/25 17:28:44 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_2(t_stack **a)
{
	if (!is_sorted(*a))
		sa(a, 1);
}

void	sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a, 1);
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		ra(a, 1);
		sa(a, 1);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		ra(a, 1);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value)
	{
		if ((*a)->value > (*a)->next->next->value)
			rra(a, 1);
		else
		{
			sa(a, 1);
			ra(a, 1);
		}
	}
}

int	get_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

void	min_in_head(t_stack **a, int min, int size)
{
	int		i;
	t_stack	*ptr;

	ptr = *a;
	i = 0;
	while (ptr->value != min)
	{
		i++;
		ptr = ptr->next;
	}
	if (i < size / 2)
		while ((*a)->value != min)
			sa(a, 1);
	else
		while ((*a)->value != min)
			rra(a, 1);
}

void	sort_5(t_stack **a, t_stack **b, int size)
{
	int	min;

	min = INT_MIN;
	while (size > 3)
	{
		if ((*a)->index == 1 || (*a)->index == 0)
			pb(a, b);
		else
		{
			min = get_min(*a);
			min_in_head(a, min, size);
			pb(a, b);
		}
		size--;
	}
	if (lstsize(b) > 1 && is_sorted(*b))
		sb(b, 1);
	sort_3(a);
	while (*b)
		pa(a, b);
}
