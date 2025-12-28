/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:22:47 by hahchtar          #+#    #+#             */
/*   Updated: 2025/11/14 17:29:53 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strdup(char *str);
int		read_from_fd(int fd, char **remainder);
char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
char	*ft_strchr(const char *str, char c);
size_t	ft_strlen(const char *str);
#endif
