/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:26 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/27 14:40:27 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef	struct		s_list
{
	int             data;
	int				index;
	struct s_list	*next;
    struct s_list	*prev;
    
}					t_list;

typedef struct s_stacks
{
	t_list *a;
	t_list *b;
	int		size_a;
	int		size_b;
}       t_stacks;

t_list	*ft_lstnew(int content, int index);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_delete_front(t_list **lst);
void	swap(t_list *stack);
void	do_ss(t_stacks *s);
void	do_pa(t_stacks *s);
void	do_pb(t_stacks *s);
void	rotate(t_list **stack);
void	do_rr(t_stacks *s);
void	rrotate(t_list **stack);
void	do_rrr(t_stacks *s);
void    parsing(t_stacks *s, int argc, char **argv);
int		ft_atoi(char *str);
char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
void    alg_5(t_stacks *s);
int		find_min(t_list *s);
void	indexing(t_list *s, int size);
void    alg_100(t_stacks *s);
void	second(t_stacks *s);
int is_sorted(t_stacks *s);
void my_idea(t_stacks *s);
int find_max(t_list *s);
void    alg_500(t_stacks *s);



#endif