/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:25:18 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 13:43:07 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_putunsigned_hex(unsigned int num, char i);
int	ft_putptr(void *ptr);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_printf(const char *format, ...);
#endif
