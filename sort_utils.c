/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 15:30:00 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/21 10:52:12 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexs(t_stack *a)
{
	int		i;
	t_stack	*ptr;
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		i = 0;
		ptr = tmp;
		while (ptr)
		{
			if (ptr->value < a->value)
				i++;
			ptr = ptr->next;
		}
		a->index = i;
		a = a->next;
	}
}

int	is_sorted(t_stack *head)
{
	while (head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
