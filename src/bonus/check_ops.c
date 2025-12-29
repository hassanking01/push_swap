/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 01:23:40 by hassan            #+#    #+#             */
/*   Updated: 2025/12/29 01:32:22 by hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	check_swap(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n"))
		sa(a, 0);
	else if (ft_strcmp(str, "sb\n"))
		sb(b, 0);
	else if (ft_strcmp(str, "ss\n"))
		ss(a, b, 0);
	else
		return (0);
	return (1);
}
int	check_push(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "pa\n"))
		pa(a, b, 0);
	else if (ft_strcmp(str, "pb\n"))
		pb(a, b, 0);
	else
		return (0);
	return (1);
}

int	check_rotate(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "ra\n"))
		ra(a, 0);
	else if (ft_strcmp(str, "rb\n"))
		rb(b, 0);
	else if (ft_strcmp(str, "rr\n"))
		rr(a, b, 0);
	else
		return (0);
	return (1);
}

int	check_rev_rotate(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "rra\n"))
		rra(a, 0);
	else if (ft_strcmp(str, "rrb\n"))
		rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}
