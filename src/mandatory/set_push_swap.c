/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:48:56 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/25 18:48:57 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

void	set_push_swap(t_stack **a, t_stack **b)
{
	int	size;

	size = lstsize(a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b, size);
	else
		push_swap(a, b, size);
}
