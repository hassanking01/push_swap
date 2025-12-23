/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:55:13 by hahchtar          #+#    #+#             */
/*   Updated: 2025/11/20 22:03:10 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_hex(unsigned int num, char i)
{
	char			*nums;
	unsigned int	pow;
	int				count;
	unsigned int	base;

	nums = "0123456789abcdef";
	count = 0;
	pow = 1;
	if (i == 'u')
		base = 10;
	else
		base = 16;
	if (i == 'X')
		nums = "0123456789ABCDEF";
	while (num / pow >= base)
		pow *= base;
	while (pow)
	{
		ft_putchar(nums[num / pow]);
		num %= pow;
		pow /= base;
		count++;
	}
	return (count);
}
