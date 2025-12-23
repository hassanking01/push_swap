#include "push_swap.h"

void lstaddack(t_stack ** head, t_stack * new)
{
    t_stack * ptr;

    if (!head || !new)
        return;
    if (!*head)
    {
        *head = new;
        return ;
    }
    ptr = *head;
    while(ptr->next)
        ptr = ptr->next;
    ptr->next = new;
}
t_stack *lst_new(int value)
{
    t_stack *ptr;

    ptr = malloc(sizeof(t_stack));
    if (!ptr)
        return (NULL);
    ptr->value = value;
    ptr->index = -1;
    ptr->next = NULL;
    return (ptr);
}
void ft_lstclean(t_stack ** head)
{
    t_stack * ptr;
    t_stack * tmp;

    ptr = *head;
    while(ptr)
    {
        tmp = ptr->next;
        free(ptr);
        ptr = tmp;
    }
}
void ft_clean(char ** av, t_stack ** head, int is_one)
{
    if(is_one)
        free_re(av);
    if(*head)
        ft_lstclean(head);
}
void set_stack_a(t_stack ** head, char ** av , int is_one)
{
    int i;
    t_stack * newNode;
    i = 1;
    while (av[i])
    {
        newNode = lst_new(ft_atoi(av[i]));
        if(!newNode)
        {
            ft_clean(av, head , is_one);
            exit(1);
        }
        lstaddack(head, newNode);
        i++;
    }
    
}
int lstsize(t_stack ** head)
{
    t_stack *ptr;
    int size;

    if(!head || !*head)
        return (0);
    ptr = *head;
    size = 0;
    while(ptr)
    {
        size++;
        ptr = ptr->next;
    }
    return (size);
}