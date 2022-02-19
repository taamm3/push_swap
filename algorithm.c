#include "push_swap.h"

void    alg_3(t_stacks *s)
{
    if(s->a->data > s->a->next->data && s->a->data < s->a->next->next->data)
        {
            swap(s->a);
            write(1, "sa\n", 3);
        }
    else if(s->a->data < s->a->next->data && s->a->next->data < s->a->next->next->data)
        ;
    else if(s->a->data > s->a->next->data && s->a->next->data > s->a->next->next->data)
    {
        swap(s->a);
        write(1, "sa\n", 3);
        rrotate(&s->a);
        write(1, "rra\n", 4);
    }
    else if(s->a->data > s->a->next->data && s->a->next->data < s->a->next->next->data)
    {
        rotate(&s->a);
        write(1, "ra\n", 3);
    }
    else if(s->a->data < s->a->next->data && s->a->data < s->a->next->next->data)
    {
        swap(s->a);
        write(1, "sa\n", 3);
        rotate(&s->a);
        write(1, "ra\n", 3);
    }
    else if(s->a->data < s->a->next->data && s->a->next->data > s->a->next->next->data)
    {
        rrotate(&s->a);
        write(1, "rra\n", 4);
    }
}

void    alg_5(t_stacks *s)
{
    int min, index;
    t_list *tmp;

    while(s->size_a != 3)
    {
        tmp = s->a;
        index = 0;
        min = find_min(s->a);
        while(min != tmp->data)
        {
            tmp = tmp->next;
            index++;
        }
        if(index <= s->size_a / 2)
        while(index != 0)
        {
            rotate(&s->a);
            write(1, "ra\n", 3);
            index--;
        }
        else
         while(s->size_a - index != 0)
        {
            rrotate(&s->a);
            write(1, "rra\n", 4);
            index++;
        }
        do_pb(s);
        write(1, "pb\n", 3);
    }
    alg_3(s);
    while(s->size_b != 0)
    {
    do_pa(s);
    write(1, "pa\n", 3);
    }
}

int find_min(t_list *s)
{
    t_list *tmp;
    int min;

    tmp = s;
    while(tmp->index != -1)
        tmp = tmp->next;
    min = tmp->data;
    tmp = s->next;
    while(tmp->data != s->data)
    {
        if(min > tmp->data && tmp->index == -1)
            min = tmp->data;
        tmp = tmp->next;
    }
    return (min);
}

void indexing(t_list *s, int size)
{
    t_list *tmp;
    int min;
    int index = 0;

    while(index < size)
    {
        tmp = s;
        min = find_min(s);
        while(min != tmp->data)
            tmp = tmp->next;
        tmp->index = index;
        index++;
    }
}

int find_max(t_list *s)
{
    t_list *tmp;
    int max;

    max = s->data;
    tmp = s->next;
    while(tmp->data != s->data)
    {
        if(max < tmp->data)
            max = tmp->data;
        tmp = tmp->next;
    }
    return (max);
}
