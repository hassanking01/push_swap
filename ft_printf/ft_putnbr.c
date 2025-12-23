/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:06:51 by hahchtar          #+#    #+#             */
/*   Updated: 2025/11/20 22:02:57 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	m;
	int		count;

	count = 0;
	m = n;
	if (n < 0)
	{
		m = -m;
		count += ft_putchar('-');
	}
	if (m < 10)
	{
		count += ft_putchar(m + '0');
		return (count);
	}
	if (m >= 10)
		count += ft_putnbr(m / 10);
	count += ft_putchar(m % 10 + '0');
	return (count);
}
