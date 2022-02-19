/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:41:13 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/27 14:41:14 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	if (!n)
		return (0);
	i = 0;
	while (i < n && st1[i] && st2[i] && st1[i] == st2[i])
		i++;
	if (i < n)
		return (st1[i] - st2[i]);
	else
		return (0);
}

void    parsing(t_stacks *s, int argc, char **argv)
{
    int i = 0, j, a = 1;
	t_list *new;
    char **m;
    int count;
    int n = 0;

    if(argc == 2)
    {
        if (ft_strncmp(argv[1],"\0",1) == 0)
        {
            write(1,"Error\n",6);
            exit(0);
        }
        while(argv[1][n] == ' ')
        {
            n++;
        }
        if(argv[1][n] == '\0')
        {
            write(1,"Error\n",6);
            exit(0);
        }
        m = ft_split(argv[1], ' ');
        while(m[i] != NULL)
        {
            j = 0;
            while(m[i][j] != '\0')
                j++;
            i++;
        }
        count = i;
        s->size_a = i;
        a = 0;
    }
    else if (argc > 2)
    {
        count = argc;
        s->size_a = argc - 1;
        m = argv;
    }   
    if(argc >= 2)
    {
        i = a;
        while(i < count)
        {
            j = a;
            while(j < i)
            {
                if(ft_atoi(m[i]) == ft_atoi(m[j])) 
                {
                    write(1,"Error\n",6);
                    exit(0);
                }
                j++;
            }
            i++;
        }

        i = count - 1;
        s->a = ft_lstnew(ft_atoi(m[i]), -2);
        i--;

        while(i >= a)
        {
            new = ft_lstnew(ft_atoi(m[i]), -2);
            ft_lstadd_front(&s->a, new);
            i--;
        }
        if(argc == 2)
        {
            i = 0;
            while(m[i] != NULL)
            {
                free(m[i]);
                i++;
            }
            free(m);
        }
    }
}