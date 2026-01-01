/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:23:18 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 14:42:05 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

char	*ft_strndup(char *str, int size)
{
	int		i;
	char	*re;

	re = malloc(sizeof(char) * size + 1);
	if (!re)
		return (NULL);
	i = 0;
	while (i < size)
	{
		re[i] = str[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
