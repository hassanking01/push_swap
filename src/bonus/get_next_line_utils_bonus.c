/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:28:14 by hahchtar          #+#    #+#             */
/*   Updated: 2026/01/01 14:42:16 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_bonus.h"

int	read_from_fd(int fd, char **remainder)
{
	char	*buffer;
	int		end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (0);
	end = 1;
	while (end)
	{
		end = read(fd, buffer, BUFFER_SIZE);
		if (end < 0)
			break ;
		buffer[end] = '\0';
		*remainder = ft_join(*remainder, buffer);
		if (!(*remainder))
			break ;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	if (!(*remainder) || end < 0)
		return (0);
	return (1);
}

char	*ft_strchr(const char *str, char c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == c)
			return (ptr);
		ptr++;
	}
	if (!c)
		return (ptr);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	i = ft_strlen(str);
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(char *s1, char *s2)
{
	char	*ptr;
	size_t	len;
	size_t	i;
	char	*tmp;

	tmp = s1;
	i = 0;
	len = 0;
	if (s1)
		len = ft_strlen(s1);
	len = len + ft_strlen(s2);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		while (*s1)
			ptr[i++] = *s1++;
	while (*s2)
		ptr[i++] = *s2++;
	ptr[i] = '\0';
	free(tmp);
	return (ptr);
}
