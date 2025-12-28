/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 16:12:54 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/24 16:13:16 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	lstaddack(t_stack **head, t_stack *new)
{
	t_stack	*ptr;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

t_stack	*lst_new(int value)
{
	t_stack	*ptr;

	ptr = malloc(sizeof(t_stack));
	if (!ptr)
		return (NULL);
	ptr->value = value;
	ptr->index = -1;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstclean(t_stack **head)
{
	t_stack	*ptr;
	t_stack	*tmp;

	ptr = *head;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
}

void	ft_clean(char **av, t_stack **head)
{
	free_re(av);
	if (*head)
		ft_lstclean(head);
}

int	lstsize(t_stack **head)
{
	t_stack	*ptr;
	int		size;

	if (!head || !*head)
		return (0);
	ptr = *head;
	size = 0;
	while (ptr)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
