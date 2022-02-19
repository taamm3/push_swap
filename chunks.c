#include "push_swap.h"

void    alg_100(t_stacks *s)
{
    int ch = s->size_a/5;
    int i = 0;
    int t = 0, b = 0;
    t_list *tmp;
    int size = s->size_a;

    indexing(s->a, s->size_a);
    while(s->size_a)
    {
        while(i < ch && i < size)
        {
            tmp = s->a;
            while(tmp->index >= ch)
            {
                tmp = tmp->next;
                t++;
            }
            tmp = s->a;
            while(tmp->index >= ch)
            {
                tmp = tmp->prev;
                b++;
            }
            if(t < b)
                while(t != 0)
                {
                    rotate(&s->a);
                    write(1, "ra\n", 3);
                    t--;
                }
            else 
                while(b != 0)
                {
                    rrotate(&s->a);
                    write(1, "rra\n", 4);
                    b--;
                }
            do_pb(s);
            write(1, "pb\n", 3);
            i++;
        }
        ch += size/5;
    }
    my_idea(s);
}

void my_idea(t_stacks *s)
{

    t_list *tmp;
    int index, max;

    while(s->size_b > 0)
    {
        tmp = s->b;
        index = 0;
        max = find_max(s->b);
        while(max != tmp->data)
        {
            tmp = tmp->next;
            index++;
        }
        if(index <= s->size_b / 2)
        while(index != 0)
        {
            rotate(&s->b);
            write(1, "rb\n", 3);
            index--;
        }
        else
         while(s->size_b - index != 0)
        {
            rrotate(&s->b);
            write(1, "rrb\n", 4);
            index++;
        }
        do_pa(s);
        write(1, "pa\n", 3);
    }
}

void    alg_500(t_stacks *s)
{
    int ch = s->size_a/11;
    int i = 0;
    int t = 0, b = 0;
    t_list *tmp;
    int size = s->size_a;

    indexing(s->a, s->size_a);
    while(s->size_a)
    {
        while(i < ch && i < size)
        {
            tmp = s->a;
            while(tmp->index >= ch)
            {
                tmp = tmp->next;
                t++;
            }
            tmp = s->a;
            while(tmp->index >= ch)
            {
                tmp = tmp->prev;
                b++;
            }
            if(t < b)
                while(t != 0)
                {
                    rotate(&s->a);
                    write(1, "ra\n", 3);
                    t--;
                }
            else 
                while(b != 0)
                {
                    rrotate(&s->a);
                    write(1, "rra\n", 4);
                    b--;
                }
            do_pb(s);
            write(1, "pb\n", 3);
            i++;
        }
        ch += size/11;
    }
    my_idea(s);
}