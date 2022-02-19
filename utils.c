/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapetros <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 14:40:59 by tapetros          #+#    #+#             */
/*   Updated: 2021/07/27 14:41:01 by tapetros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if(!new)
		return;
	
	if(*lst)
	{
		new->prev = (*lst)->prev; 
		new->next = *lst;
		((*lst)->prev)->next = new;
		(*lst)->prev = new;
		*lst = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstnew(int content, int index)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(t_list))))
		return (0);

	l->data = content;
	if(index == -2)
		l->index = -1;
	else
		l->index = index;
	l->next = l;
	l->prev = l;
	return (l);
}

void	ft_delete_front(t_list **lst)
{
	t_list *tmp;

	if(*lst)
	{
		if((*lst)->next == *lst)
		{
			free(*lst);
			*lst = NULL;
		}
		else
		{
			tmp = *lst;
			*lst = (*lst)->next;
			tmp->prev->next = *lst;
			(*lst)->prev = tmp->prev;
			free(tmp);
		}
	}
}

int		ft_atoi(char *str)
{
	int i;
	int min;
	long num;

	i = 0;
	num = 0;
	min = 1;
	while (str[i] == ' ' || str[i] == '\t' ||
			str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		num = num * 10;
		num = num + str[i] - '0';
		i++;
		if(num > 2147483647)
		{
			write(1,"Error\n",6);
			exit(0);
		}
	}
	if(str[i] != '\0')
	{
		write(1,"Error\n",6);
        exit(0);
	}
	if(num == 0 && min == -1)
	{
		write(1,"Taron heriqa, nshanaki prcnem es projectic\n",44);
        exit(0);
	}
	return (num * min);
}

static int		sp(char const *str, char c)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i++] != c)
			j++;
		if (j)
			count++;
	}
	return (count);
}

static char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	unsigned int	l;
	int	i;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (!(str = (char*)malloc(l + 1)))
		return (NULL);
	i = 0;
	while (i < len && i + start < l)
	{
		str[i] = s[start + i];
		++i;
	}
	str[i] = '\0';
	return (str);
}

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	int		k;
	int		count;
	char	**d;

	i = 0;
	k = 0;
	count = sp(s, c);
	d = malloc((count + 1) * sizeof(char*));
	while (i < count)
	{
		j = 0;
		while (s[k] && s[k++] != c)
			j++;
		if (j)
		{
			if (s[k] || s[ft_strlen(s) - 1] == c)
				d[i++] = ft_substr(s, (k - j - 1), j);
			else
				d[i++] = ft_substr(s, (k - j), j);
		}
	}
	d[i] = 0;
	return (d);
}

int is_sorted(t_stacks *s)
{
	t_list *tmp;
	int i = 0;

	tmp = s->a;
	while(i < s->size_a - 1)
	{
	    if(tmp->data > tmp->next->data)
			return (0);
	    i++;
		tmp = tmp->next;
	}
	return (1);
}