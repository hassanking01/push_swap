/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:35:29 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/25 17:23:09 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	word_count(char **strs)
{
	int		i;
	int		count;
	char	*str;

	count = 0;
	while (*strs)
	{
		i = 0;
		str = *strs;
		if (!str[0])
			return (-1);
		while (str[i])
		{
			while (str[i] == ' ' && str[i])
				i++;
			if (str[i])
				count++;
			while (str[i] != ' ' && str[i])
				i++;
		}
		strs++;
	}
	return (count);
}

int	free_re(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (0);
}

int	is_done_duplacete(char **re, char **ptr, char *str)
{
	int	i;

	i = 0;
	while (*ptr)
		ptr++;
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		if (*str)
		{
			i = 0;
			while (str[i] != ' ' && str[i])
				i++;
			*ptr = ft_strndup(str, i);
			if (!(*ptr))
				return (free_re(re));
			ptr++;
		}
		while (*str != ' ' && *str)
			str++;
	}
	ptr = NULL;
	return (1);
}

int	fill_array(char **re, char **str)
{
	char	**ptr;

	ptr = re;
	while (*str)
	{
		if (!is_done_duplacete(re, ptr, *str))
			return (0);
		str++;
	}
	return (1);
}

char	**ft_split(char **str)
{
	int		count;
	char	**re;
	int		i;

	count = word_count(str) + 1;
	if (!count)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	re = malloc(sizeof(char *) * count);
	if (!re)
		return (NULL);
	i = 0;
	while (i < count)
	{
		re[i] = NULL;
		i++;
	}
	if (fill_array(re, str))
		return (re);
	return (NULL);
}
