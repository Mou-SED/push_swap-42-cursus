/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:46:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/04/12 17:53:55 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_sorted(t_d_list *p_stack)
{   
	int value;
	
	if(p_stack == NULL || p_stack->next == NULL)
		return (1);
	else if(p_stack->content < p_stack->next->content)
		value = 1;
	else if(p_stack->content > p_stack->next->content)
		value = 0;
	return (is_sorted(p_stack->next) * value);
}

int get_max_number(t_d_list stk_a)
{
	int i;
	int max;
	t_d_list *tmp;
	
	i = 0;
	tmp = &stk_a;
	max = stk_a.content;
	while (tmp)
	{
		if(tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int get_min_number(t_d_list stk_a)
{
	int i;
	int min;
	t_d_list *tmp;
	
	i = 0;
	tmp = &stk_a;
	min = stk_a.content;
	while (tmp)
	{
		if(tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	
	return (min);
}

int len_div_2(t_d_list top, int len)
{
	t_d_list *tmp;
	int i;

	tmp = &top;
	i = 0;
	while(len/2 > i && tmp->next)
		{
			tmp = tmp->next;
			i++;
		}
	return (tmp->content);
}

int check_mid(t_d_list *top, int mid, char c)
{
	t_d_list *tmp;

	tmp = top;
	while(tmp != NULL)
	{
		if (c == 'a')
		{
			if(tmp->content <= mid)
				return (1);
		}
		if (c == 'b')
		{
			if(tmp->content >= mid)
				return (1);
		}
		tmp = tmp->next;	
	}
	return (0);
}

int	find_mid(t_d_list top, int len)
{
	int swap;
	t_d_list *tmp;
	t_d_list *tmp2;
	t_d_list *head;
	
	tmp = duplicate_stack(&top, len);
	head = tmp;
	while (!is_sorted(head) && tmp != NULL)
	{
		tmp2 = tmp->next;
		while(tmp2)
		{
			if (tmp->content > tmp2->content)
			{
				swap = tmp->content;
				tmp->content = tmp2->content;
				tmp2->content = swap;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (len_div_2(*head, len));
}
