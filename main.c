/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:34 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/27 14:40:36 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stacks s;
	
	s.size_a = 0;
	parsing(&s, argc, argv);
	if(is_sorted(&s))
	{
		while(s.size_a)
		{
			ft_delete_front(&s.a);
			s.size_a--;
		}
		return (0);
	}	
	if(s.size_a == 2 && s.a->data > s.a->next->data)
		{
			swap(s.a);
			write(1, "sa\n", 3);
		}
	else if(s.size_a <= 5 && s.size_a > 2)
		alg_5(&s);
	else if(s.size_a >= 6 && s.size_a <= 100)
		alg_100(&s);
	else if(s.size_a > 100)
		alg_500(&s);

	while(s.size_a)
	{
		ft_delete_front(&s.a);
		s.size_a--;
	}
	return (0);
}