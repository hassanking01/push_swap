/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:20:30 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/29 01:32:23 by hassan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_oppirations(char *op, t_stack **a, t_stack **b)
{
	int	len;
	int	result;

	len = ft_strlen(op);
	if (len == 3)
		if (op[0] == 's')
			result = check_swap(op, a, b);
		else if (op[0] == 'p')
			result = check_push(op, a, b);
		else if (op[0] == 'r')
			result = check_rotate(op, a, b);
		else
			result = 0;
	else if (len == 4)
		result = check_rev_rotate(op, a, b);
	else
		result = 0;
	return (result);
}
void	free_everything(char **av, t_stack **a, t_stack **b)
{
	while ((*b))
		pb(a, b ,0);
	ft_clean(av, a);
}
int	run_ops(char **av, t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!check_oppirations(line, a, b))
		{
			free_everything(av, a, b);
			free(line);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}
int	main(int ac, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**av;
	int		i;

	av = argv;
	av++;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	av = ft_split(av);
	i = 0;
	if (!check_error(av))
		return (0);
	set_stack_a(&a, av);
	if (run_ops(av, &a, &b))
		if (is_sorted(a))
			write(1, "ok\n", 3);
		else
			write(1, "ko\n", 3);
	free_everything(av, &a, &b);
	return (0);
}
