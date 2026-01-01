/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:35:20 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 14:41:52 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	skip_space(int *i, char *str)
{
	int	j;

	j = 0;
	while (str[j] == ' ' && str[j])
		j++;
	*i = j;
}

long	ft_atoi(char *str)
{
	int		i;
	long	re;
	int		sign;

	i = 0;
	sign = 1;
	re = 0;
	skip_space(&i, str);
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (41474836488);
		re = (re * 10) + (str[i] - '0');
		if (re > 2147483648)
			return (41474836488);
		i++;
	}
	re = re * sign;
	if (re <= 2147483647 && re >= -2147483648)
		return (re);
	return (41474836488);
}
