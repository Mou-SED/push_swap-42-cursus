/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:46:46 by moseddik          #+#    #+#             */
/*   Updated: 2022/05/04 10:27:54 by moseddik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int is_sorted(t_d_list *p_stack)
{   
	int value;

	value = 0;
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
	int max;
	t_d_list *tmp;
	
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
	int min;
	t_d_list *tmp;
	
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

int check_mid(t_d_list *top_stack, int mid, char c)
{
	t_d_list *tmp;

	tmp = top_stack;
	while(tmp != NULL)
	{
		if (c == 'a')
			if(tmp->content <= mid)
				return (1);
		if (c == 'b')
			if(tmp->content >= mid)
				return (1);
		tmp = tmp->next;	
	}
	return (0);
}

t_d_list	*sort_duplicate_stack(t_d_list *dupl_stk)
{
	int			swap;
	t_d_list	*head;
	t_d_list	*tmp;
	
	head = dupl_stk;
	while (!is_sorted(head) && dupl_stk != NULL)
	{
		tmp = dupl_stk->next;
		while(tmp)
		{
			if (dupl_stk->content > tmp->content)
			{
				swap = dupl_stk->content;
				dupl_stk->content = tmp->content;
				tmp->content = swap;
			}
			tmp = tmp->next;
		}
		dupl_stk = dupl_stk->next;
	}
	return (head);
}

int	find_mid(t_stk *top, int len, char stack_name)
{
	t_d_list *dupl_stk;
	t_d_list *stack;
	t_d_list *head;
	
	if (stack_name == 'a')
		stack = top->stk_a;
	if (stack_name == 'b')
		stack = top->stk_b;

	dupl_stk = duplicate_stack(stack, len - 1);
	if (dupl_stk == NULL)
	{
		free_tab_without_index(top->spl);
		ft_d_lstclear(&stack, &free);
		exit(-1);
	}
	head = sort_duplicate_stack(dupl_stk);
	return (len_div_2(*head, len));
}
