/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 09:30:37 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/21 10:06:05 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
        if((*a)->value > (*a)->next->next->value)
            rra(a , 1);
        else
        {
        sa(a,1);
        ra(a, 1);
        }
    }
}

int get_min(t_stack * a)
{
	int min;

	min = a->value;
	while(a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}
void min_in_head(t_stack ** a, int min, int size)
{
	int i;
	t_stack *ptr;

	ptr = *a;
	i = 0;
	while(ptr->value != min)
	{
		i++;
		ptr = ptr->next;
	}
	if (i < size / 2  )
		while ((*a)->value != min)
			sa(a, 1);
	else
		while((*a)->value != min)
			rra(a, 1);
}
void	sort_5(t_stack **a, t_stack **b, int size)
{
	int min;

	while(size > 3)
	{
		if ((*a)->index == 1 || (*a)->index == 0)
		{
			pb(a ,b);
			size--;
		}
		else
		{
		min = get_min(*a);
		min_in_head(a, min, size);
		pb(a, b);
		size--;
		}
	}
	sort_3(a);
	while(*b)
		pa(a, b);
}
#include <limits.h>
int big_po(t_stack * ptr)
{
	int i = 0;
	t_stack * tmp;
	int big = INT_MIN;
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
void pos(t_stack ** b , int i , t_stack * ptr)
{
	int size = lstsize(b);
			if (i >= size / 2)
			{
				while ((*b)->value != ptr->value)
					{
						rrb(b, 1);
					}
			}
			else
			{
				while ((*b)->value != ptr->value)
				{
					rb(b , 1);
				}
			}
}
t_stack * find(t_stack * b , int index)
{
	while (index--)
		b = b->next;
	return (b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int i;

	i = 0;
	int chunk_size = lstsize(a);
	if (chunk_size > 100)
		chunk_size = 35;
	else
		chunk_size = 15;
	while ((*a))
	{
		if((*a)->index <= i)
		{
			pb(a, b);
			rb(b, 1);
			i++;
		}
		else if ((*a)->index < i + chunk_size)
		{
			pb(a, b);
			i++;
		}else
			ra(a, 1);
		
	}
	i = 0;

	while (*b)
	{
		t_stack * ptr = *b;

		i = big_po(ptr);
		//ptr = *b;
		ptr = find(*b , i);
		pos(b , i  , ptr);
		pa(a, b);	
	}
	
}
