/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:23:08 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/24 15:23:53 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_stack_a(t_stack **head, char **av)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	while (av[i])
	{
		new_node = lst_new(ft_atoi(av[i]));
		if (!new_node)
		{
			ft_clean(av, head);
			exit(1);
		}
		lstaddack(head, new_node);
		i++;
	}
}

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

