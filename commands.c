#include "push_swap.h"

void swap(t_list *stack)
{
    int temp;
    int temp_i;

    if(stack && stack->next != stack)
    {
        temp = stack->data;
        stack->data = stack->next->data;
        stack->next->data = temp;
        temp_i = stack->index;
        stack->index = stack->next->index;
        stack->next->index = temp_i;
    }
}

void do_ss(t_stacks *s)
{
    swap(s->a);
    swap(s->b);
}

void do_pa(t_stacks *s)
{
    t_list *new;

    if(s->b)
    {
        new = ft_lstnew(s->b->data, s->b->index);
        ft_lstadd_front(&s->a,new);
        ft_delete_front(&s->b);
        s->size_a++;
        s->size_b--;
    }
}

void do_pb(t_stacks *s)
{
    t_list *new;

    if(s->a)
    {
        new = ft_lstnew(s->a->data, s->a->index);
        ft_lstadd_front(&s->b, new);     
        ft_delete_front(&s->a);
        s->size_a--;
        s->size_b++;
    }
}

void rotate(t_list **stack)
{
    *stack = (*stack)->next;
}

void do_rr(t_stacks *s)
{
    rotate(&s->a);
    rotate(&s->b);
}

void rrotate(t_list **stack)
{
    *stack = (*stack)->prev;
}

void do_rrr(t_stacks *s)
{
    rrotate(&s->a);
    rrotate(&s->b);
}