/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:22:26 by hahchtar          #+#    #+#             */
/*   Updated: 2025/11/20 22:03:03 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_long_hex(unsigned long num)
{
	char			*nums;
	unsigned long	pow;
	int				count;

	count = 0;
	pow = 1;
	nums = "0123456789abcdef";
	while (num / pow >= 16)
		pow *= 16;
	while (pow)
	{
		ft_putchar(nums[num / pow]);
		num %= pow;
		pow /= 16;
		count++;
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long	m;
	int				count;

	count = 0;
	if (!ptr)
	{
		ft_putstr("(nil)");
		count = 5;
	}
	else
	{
		m = (unsigned long)ptr;
		ft_putstr("0x");
		count = ft_putunsigned_long_hex(m) + 2;
	}
	return (count);
}
