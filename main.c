/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:31:16 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/18 16:36:39 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
void skip_space(int * i, char * str)
{
	int j;

	j = 0;
	while (str[j] == ' ' && str[j])
		j++;
	*i = j;
}
long ft_atoi(char * str)
{
	int i;
	long re;
	int sign;

	i = 0;
	sign = 1;
	re = 0;
	skip_space(&i, str);
	if (str[i] == '-' || str[i] == '+')
		if(str[i++] == '-')
			sign *= -1;
	if(!str[i])
		return (41474836488);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (41474836488);
		re = (re * 10) + (str[i] -  '0');
		i++;
	}
	re = re  * sign;
	if(re <= 2147483647 && re >= -2147483648)
		return(re);
	return (41474836488);
}
int word_count(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while(str[i] == ' ' && str[i])
			i++;
		if(str[i])
			count++;
		while(str[i] != ' ' && str[i])
			i++;
	}
	return (count);
}
char * ft_dup(char *str, int size)
{
	int i;
	char *re;

	re = malloc(sizeof(char) * size + 1);
	if(!re)
		return (NULL);
	i=  0;
	while(i < size)
	{
		re[i] = str[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
int free_re(char ** ptr)
{
	int i;

	i = 1;
	while(ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (0);
}
int fill_array(char ** re, char *str)
{
	char **ptr;
	int i;
	int j;

	j = 1;
	ptr = re;
	while(*str)
	{
		while(*str == ' ' && *str)
			str++;
		if(*str)
		{
			i = 0;
			while(str[i] != ' ' && str[i])
				i++;
			ptr[j] = ft_dup(str, i);
			if(!ptr[j])
				return (free_re(ptr));
			j++;
			while(*str != ' ' && *str)
				*str++;
		}
	}
	ptr[j] = NULL;
	return (1);
}
char ** ft_split(char *str, int ac , char * av_0 , int * is_one)
{
	int count;
	char ** re;

	if (ac == 1)
		exit(0);
	*is_one = 1;
	count = word_count(str) + 2;
	re = malloc(sizeof(char *) * count);
	if(!re)
		return (NULL);
	re[0] = av_0;
	if(fill_array(re, str))
		return (re);
	return (NULL);
}

int check_duplicate(char ** av , int i)
{

	int j;

	j = 1;
	while(av[j])
		{
			if(ft_atoi(av[j]) == ft_atoi(av[i]) && j != i)
				return (1);
			j++;
		}
		i++;
	
	return (0);
}

int check_error(char ** av , int is_one_arg)
{
	int i;

	i = 1;
	while (av[i])
	{
		if(ft_atoi(av[i]) > 2147483647 || check_duplicate(av, i))
		{
			write(2 ,"Error\n" , 6);
			if(is_one_arg)
				free_re(av);
			return (0);
		}
		i++;
	}
	return (1);
}

void set_push_swap(t_stack ** a, t_stack ** b)
{
	int size;

	size = lstsize(a);
	if(size == 2)
		sort_2(a);
	else if(size == 3)
		sort_3(a);
	else if(size <= 5)
		sort_5(a , b, size);
	else
		push_swap(a , b);
}
void print_stack(t_stack * head)
{
	while(head)
	{
		ft_printf("%d%s", head->value , head->next ? " --> " : "\n" );
		head = head->next;
	}
}
int	main(int ac, char *av[])
{
	t_stack	*a = NULL;
	t_stack *b = NULL;
	
	int is_one;

	is_one = 0;
	if (ac < 2)
		return (1);
	//char *str = "5 6 3 2 8 7 9 1 0";
	if (ac == 2)
		av = ft_split(av[1], ac , av[0], &is_one);
	if(!check_error(av,  is_one))
		return (0);
	set_stack_a(&a , av , is_one);
	if (is_sorted(a))
	{
		ft_clean(av, &a, is_one);
		return (0);
	}
	set_indexs(a);

	set_push_swap(&a, &b);

	//print_stack(a);
	// if(is_sorted(a))
	// 	ft_printf("all good\n");
	// else
	//	ft_printf("fix this\n");
	ft_clean(av , &a , is_one);
	return (0);
}
