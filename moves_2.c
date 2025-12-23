/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahchtar <hahchtar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:55:31 by hahchtar          #+#    #+#             */
/*   Updated: 2025/12/18 17:55:32 by hahchtar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void ra(t_stack ** a, int flag)
{
    t_stack * ptr;

    if (!a || !(*a))
        return ;
    ptr = *a;
    (*a) = (*a)->next;
    ptr->next = NULL;
    lstaddack(a , ptr);
    if(flag)
        ft_printf("ra\n");
}
void rb(t_stack ** b, int falg)
{
    t_stack * ptr;

    if (!b || !(*b))
        return ;
    ptr = *b;
    (*b) = (*b)->next;
    ptr->next = NULL;
    lstaddack(b , ptr);
    if(falg)
     ft_printf("rb\n");
}
void rr(t_stack ** a ,t_stack ** b)
{
    ra(a, 0);
    rb(b, 0);
    ft_printf("rr\n");
}
void rra(t_stack ** a, int flag)
{
    t_stack * ptr;
    t_stack * tmp;

    if(!a || !(*a))
        return ;
    ptr = *a;
    while (ptr->next)
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    tmp->next = NULL;
    ptr->next = *a;
    *a = ptr;
    if (flag)
        ft_printf("rra\n");
}
void rrb(t_stack ** b, int flag)
{
    t_stack * ptr;
    t_stack * tmp;

    if(!b || !(*b))
        return ;
    ptr = *b;
    while (ptr->next)
    {
        tmp = ptr;
        ptr = ptr->next;
    }
    tmp->next = NULL;
    ptr->next = *b;
    *b = ptr;
    if (flag)
        ft_printf("rrb\n");
}
void rrr(t_stack ** a, t_stack ** b)
{
    rra(a, 0);
    rrb(b, 0);
    ft_printf("rrr\n");
}