/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:20:30 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/25 17:25:52 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int check_oppirations(char * op, t_stack ** a, t_stack ** b)
{
	int len;
	int result;

	len = ft_strlen(op);
	if (len == 2)
		if (op[0] == 's')
			result = check_swap(op , a, b);
		else if (op[0] == 'p')
			result = check_push(op , a , b);
		else if (op[0] == 'r')
			result = check_rotate(op, a , b);
		else 
			result = 0;
	else if (len == 3)
		result = check_rev_rotate(op , a , b);
	else
		result = 0;
	return (result);
}
void free_everything(char **av, t_stack ** a ,t_stack ** b)
{
	while ((*b))
		pb(a, b);
	ft_clean(av, a);
}
int run_ops(char ** av, t_stack ** a, t_stack **b)
{
	char *line;

	line = get_next_line(0);
	while (line)
	{
		if(!check_oppirations(line, a , b))
		{
			free_everything(av , a , b);
			free(line);
			write(2, "Error\n",6);
			return (0);
		}
		free(line);
		line = get_next_line(0);			
	}
	return (1);
}
int	main(int ac, char **av)
{
	t_stack * a;
	t_stack * b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av = ft_split(av);
	int i = 0 ;

	if (!check_error(av))
	{
		return (0);
	}
	set_stack_a(&a, av);
	if(run_ops(av , &a , &b))
		free_everything(av , &a ,  &b);
	return (0);
}
