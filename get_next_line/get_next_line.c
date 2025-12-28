/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:13:14 by hahchtar          #+#    #+#             */
/*   Updated: 2025/11/14 19:03:57 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (j < i)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*get_remainder(char **buffer)
{
	int		i;
	char	*remainder;
	char	*str;

	str = *buffer;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	remainder = ft_strdup(&str[i]);
	free(*buffer);
	return (remainder);
}

int	check_remainder(char **remainder, char **line)
{
	char	*ptr;

	ptr = *remainder;
	if (ptr)
	{
		if (ft_strchr(ptr, '\n'))
		{
			*line = get_line(*remainder);
			if (!(*line))
				return (-1);
			*remainder = get_remainder(remainder);
			if (!(*remainder))
			{
				free(*line);
				*line = NULL;
				return (-1);
			}
			return (1);
		}
	}
	return (0);
}

char	*get_line_save_rem(char **remainder)
{
	char	*result;

	result = NULL;
	if (*remainder && *remainder[0])
	{
		if (ft_strchr(*remainder, '\n'))
		{
			result = get_line(*remainder);
			*remainder = get_remainder(remainder);
		}
		else
		{
			result = ft_strdup(*remainder);
			free(*remainder);
			*remainder = NULL;
		}
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	int			status;

	line = NULL;
	status = check_remainder(&remainder, &line);
	if (status == -1 || status == 1)
		return (line);
	if (!read_from_fd(fd, &remainder))
		return (NULL);
	line = get_line_save_rem(&remainder);
	if (remainder && *remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}
