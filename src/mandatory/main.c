/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:31:16 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:47:30 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int ac, char *agv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**av;

	av = agv;
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	av++;
	av = ft_split(av);
	if (!check_error(av))
		return (0);
	set_stack_a(&a, av);
	if (is_sorted(a))
	{
		ft_clean(av, &a);
		return (0);
	}
	set_indexs(a);
	set_push_swap(&a, &b);
	ft_clean(av, &a);
	return (0);
}
