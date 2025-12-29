/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handel_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:12:47 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:47:30 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_duplicate(char **av, int i)
{
	int	j;

	j = 0;
	while (av[j])
	{
		if (ft_atoi(av[j]) == ft_atoi(av[i]) && j != i)
			return (1);
		j++;
	}
	return (0);
}

int	check_error(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_atoi(av[i]) > 2147483647 || check_duplicate(av, i))
		{
			write(2, "Error\n", 6);
			free_re(av);
			return (0);
		}
		i++;
	}
	if (av[i] == NULL && !i)
	{
		write(2, "Error\n", 6);
		free_re(av);
		return (0);
	}
	return (1);
}
